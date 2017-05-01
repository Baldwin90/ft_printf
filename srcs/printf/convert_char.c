/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:45:40 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/21 22:45:40 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#define GET_CHAR_IDX(idx) (1<<7)|((c>>(6*(len-i-1)))&((1<<6)-1))

char		*unicode_to_utf8(wchar_t c)
{
	int		len;
	char	*str;
	int		i;

	if (c < 128)
		len = 1;
	else if (c < 2048)
		len = 2;
	else if (c < 65536)
		len = 3;
	else if (c < 1114112)
		len = 4;
	else
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (len == 1 && ((*str = (char)c) || 1))
		return (str);
	i = -1;
	while (++i < len)
		str[i] = GET_CHAR_IDX(i);
	str[0] |= (1 << 7) - (1 << (8 - len));
	return (str);
}

static int	apply_flags(char *str, t_flags *data)
{
	int		ret;
	int		nc;

	nc = 0;
	if (*str == '\0')
		nc = 1;
	if (data->minus)
		join_repeating_char(&str, ' ', data->width - nc, 0);
	else if (data->zero)
		join_repeating_char(&str, '0', data->width - nc, 1);
	else
		join_repeating_char(&str, ' ', data->width - nc, 1);
	ret = ft_strlen(str);
	if (data->minus == 1 && nc == 1)
		write(1, "\0", 1);
	ft_putstr(str);
	if (data->minus == 0 && nc == 1)
		write(1, "\0", 1);
	free(str);
	return (ret + nc);
}

int			print_char(va_list *args, t_flags *data)
{
	char	*str;

	if (data->length == 3 || data->conversion == 'C')
		str = unicode_to_utf8(va_arg(*args, wchar_t));
	else
	{
		str = (char*)malloc(sizeof(*str) * 2);
		if (!str)
			return (0);
		str[0] = (char)va_arg(*args, int);
		str[1] = '\0';
	}
	return (apply_flags(str, data));
}

int			print_invalid_converter(t_flags *data)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * 2);
	if (!str)
		return (0);
	str[0] = data->conversion;
	str[1] = '\0';
	return (apply_flags(str, data));
}
