/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:44:08 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/21 21:44:08 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	parse_arguments(char **pos, va_list *args, t_flags *data)
{
	int		i;
	int		argnum;

	i = 0;
	argnum = 0;
	while ((*pos)[i] >= '0' && (*pos)[i] <= '9')
	{
		argnum = argnum * 10 + (*pos)[i] - '0';
		i++;
	}
	if ((*pos)[i] != '$')
		return ;
	va_copy(*args, data->ap);
	while (--argnum)
		va_arg(*args, int);
	(*pos) += i + 1;
}

void	parse_flags(char **pos, t_flags *data)
{
	data->hashtag = 0;
	data->zero = 0;
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->last_pos = 0;
	while (**pos == '#' || **pos == '0' || **pos == '-' || **pos == '+' ||
			**pos == ' ' || **pos == '\'')
	{
		if (**pos == '#')
			data->hashtag = 1;
		else if (**pos == '0')
			data->zero = 1;
		else if (**pos == '-')
			data->minus = 1;
		else if (**pos == '+')
			data->plus = 1;
		else if (**pos == ' ')
			data->space = 1;
		else if (**pos == '\'')
			data->last_pos = 1;
		(*pos)++;
	}
}

void	parse_width(char **pos, va_list *args, t_flags *data)
{
	data->width = 0;
	while ((**pos >= '0' && **pos <= '9') || **pos == '*')
	{
		if (**pos == '*')
		{
			data->width = va_arg(*args, int);
			if (data->width < 0)
			{
				data->width *= -1;
				data->minus = 1;
			}
		}
		else if ((*pos)[-1] >= '0' && (*pos)[-1] <= '9')
			data->width = data->width * 10 + **pos - '0';
		else
			data->width = **pos - '0';
		(*pos)++;
	}
}

void	parse_precision(char **pos, va_list *args, t_flags *data)
{
	data->precision = -6;
	if (**pos != '.')
		return ;
	data->precision = 0;
	(*pos)++;
	if (**pos == '*')
		data->precision = va_arg(*args, int);
	else
	{
		while (**pos >= '0' && **pos <= '9')
		{
			data->precision = data->precision * 10 + **pos - '0';
			(*pos)++;
		}
	}
	while ((**pos >= '0' && **pos <= '9') || **pos == '*')
		(*pos)++;
}

void	parse_length(char **pos, t_flags *data)
{
	data->length = 0;
	if ((*pos)[0] == 'h' && (*pos)[1] == 'h')
		data->length = 1;
	else if ((*pos)[0] == 'h')
		data->length = 2;
	else if ((*pos)[0] == 'l' && (*pos)[1] != 'l')
		data->length = 3;
	else if ((*pos)[0] == 'l')
		data->length = 4;
	else if ((*pos)[0] == 'j')
		data->length = 5;
	else if ((*pos)[0] == 'z')
		data->length = 6;
	else if ((*pos)[0] == 'L')
		data->length = 7;
	else if ((*pos)[0] == 't')
		data->length = 8;
	if (data->length == 1 || data->length == 4)
		(*pos) += 2;
	else if (data->length > 0)
		(*pos)++;
}
