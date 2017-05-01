/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa_octa_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:06:49 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/21 17:06:49 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

char		*get_signed_int(va_list *args, t_flags *data, int base)
{
	intmax_t	a;

	if (data->length == 3 || data->conversion == 'D')
		a = va_arg(*args, long);
	else if (data->length == 1)
		a = (char)va_arg(*args, int);
	else if (data->length == 2)
		a = (short)va_arg(*args, int);
	else if (data->length == 4)
		a = va_arg(*args, long long);
	else if (data->length == 5)
		a = va_arg(*args, intmax_t);
	else if (data->length == 6)
		a = va_arg(*args, ssize_t);
	else if (data->length == 8)
		a = va_arg(*args, ptrdiff_t);
	else
		a = va_arg(*args, int);
	data->sign = 1;
	if (a < 0)
		data->sign = -1;
	data->num = (uintmax_t)(data->sign * a);
	return (ft_llutoa_base(data->num, base));
}

char		*get_unsigned_int(va_list *args, t_flags *data, int base)
{
	if (data->length == 5 || data->conversion == 'p')
		data->num = va_arg(*args, uintmax_t);
	else if (data->length == 3 || data->conversion == 'U'
		|| data->conversion == 'O')
		data->num = va_arg(*args, unsigned long);
	else if (data->length == 1)
		data->num = (unsigned char)va_arg(*args, unsigned int);
	else if (data->length == 2)
		data->num = (unsigned short)va_arg(*args, unsigned int);
	else if (data->length == 4)
		data->num = va_arg(*args, unsigned long long);
	else if (data->length == 6)
		data->num = va_arg(*args, size_t);
	else
		data->num = va_arg(*args, unsigned int);
	data->sign = 0;
	return (ft_llutoa_base(data->num, base));
}

int			convert_int(char *str, t_flags *data)
{
	int		ret;

	if (data->num == 0 && data->precision == 0)
		clear_string(&str);
	join_repeating_char(&str, '0', data->precision, 1);
	if (data->zero == 1 && data->minus == 0 && data->precision < 0)
	{
		join_repeating_char(&str, '0', data->width - 1, 1);
		if (data->sign == 0 || (data->plus == 0
			&& data->space == 0 && data->sign == 1))
			join_repeating_char(&str, '0', data->width, 1);
	}
	if (data->sign == -1)
		join_str_target(&str, "-", str);
	else if (data->plus == 1 && data->sign == 1)
		join_str_target(&str, "+", str);
	else if (data->space == 1 && data->sign == 1)
		join_str_target(&str, " ", str);
	if (data->minus == 1)
		join_repeating_char(&str, ' ', data->width, 0);
	join_repeating_char(&str, ' ', data->width, 1);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			convert_octa(char *str, t_flags *data)
{
	int		ret;

	if (data->num == 0 && data->precision == 0)
		clear_string(&str);
	join_repeating_char(&str, '0', data->precision, 1);
	if (data->zero == 1 && data->minus == 0 && data->precision < 0)
	{
		if (data->hashtag == 1 && data->num != 0)
			join_repeating_char(&str, '0', data->width - 1, 1);
		else
			join_repeating_char(&str, '0', data->width, 1);
	}
	if (data->hashtag == 1 && *str != '0')
		join_str_target(&str, "0", str);
	if (data->minus == 1)
		join_repeating_char(&str, ' ', data->width, 0);
	else
		join_repeating_char(&str, ' ', data->width, 1);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			convert_hexa(char *str, t_flags *data, int fmt)
{
	int		ret;

	if (data->num == 0 && data->precision == 0)
		clear_string(&str);
	join_repeating_char(&str, '0', data->precision, 1);
	if (data->zero == 1 && data->minus == 0 && data->precision < 0)
	{
		if ((data->hashtag == 1 && data->num != 0) || fmt == 1)
			join_repeating_char(&str, '0', data->width - 2, 1);
		else
			join_repeating_char(&str, '0', data->width, 1);
	}
	if ((data->hashtag == 1 && data->num != 0) || fmt == 1)
		join_str_target(&str, "0x", str);
	if (data->minus == 1)
		join_repeating_char(&str, ' ', data->width, 0);
	else
		join_repeating_char(&str, ' ', data->width, 1);
	if (data->conversion >= 'A' && data->conversion <= 'Z')
		ft_strupcase(str);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}
