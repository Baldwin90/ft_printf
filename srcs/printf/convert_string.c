/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:11:26 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/21 22:11:26 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	widechar_string_sub(char **str, int len)
{
	int		nlen;
	int		wlen;
	char	*dup;

	if (len < 0 || len >= (int)ft_strlen(*str))
		return ;
	nlen = 0;
	while ((*str)[nlen] && nlen <= len)
	{
		wlen = 1;
		if (((unsigned char)(*str)[nlen] & 240) == 240)
			wlen = 4;
		else if (((unsigned char)(*str)[nlen] & 224) == 224)
			wlen = 3;
		else if (((unsigned char)(*str)[nlen] & 192) == 192)
			wlen = 2;
		if (nlen + wlen > len)
			break ;
		nlen += wlen;
	}
	(*str)[nlen] = '\0';
	dup = ft_strdup(*str);
	free(*str);
	*str = dup;
}

static int	apply_flags(char *str, t_flags *data)
{
	int		ret;

	widechar_string_sub(&str, data->precision);
	if (data->minus == 1)
		join_repeating_char(&str, ' ', data->width, 0);
	else if (data->zero == 1)
		join_repeating_char(&str, '0', data->width, 1);
	else
		join_repeating_char(&str, ' ', data->width, 1);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			print_string(va_list *args, t_flags *data)
{
	char	*str;
	char	*tmp;
	wchar_t	*wstr;

	if (data->length == 3 || data->conversion == 'S')
	{
		if (!(wstr = va_arg(*args, wchar_t*)))
			return (apply_flags(ft_strdup("(null)"), data));
		if (!(str = (char*)malloc(sizeof(*str))))
			return (0);
		str[0] = '\0';
		while (*wstr)
		{
			tmp = unicode_to_utf8(wstr[0]);
			join_str_target(&str, str, tmp);
			free(tmp);
			wstr++;
		}
	}
	else
	{
		str = va_arg(*args, char*);
		return (apply_flags(str ? ft_strdup(str) : ft_strdup("(null)"), data));
	}
	return (apply_flags(str, data));
}
