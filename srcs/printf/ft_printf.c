/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:06:35 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/21 20:06:35 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

static int	print_conversion(char **str, va_list *args, t_flags *data)
{
	parse_arguments(str, args, data);
	parse_flags(str, data);
	parse_width(str, args, data);
	parse_precision(str, args, data);
	parse_length(str, data);
	data->conversion = ((*str)++)[0];
	if ((*str)[-1] == 'd' || (*str)[-1] == 'i' || (*str)[-1] == 'D')
		return (convert_int(get_signed_int(args, data, 10), data));
	else if ((*str)[-1] == 'u' || (*str)[-1] == 'U')
		return (convert_int(get_unsigned_int(args, data, 10), data));
	else if ((*str)[-1] == 'p')
		return (convert_hexa(get_unsigned_int(args, data, 16), data, 1));
	else if ((*str)[-1] == 'x' || (*str)[-1] == 'X')
		return (convert_hexa(get_unsigned_int(args, data, 16), data, 0));
	else if ((*str)[-1] == 'o' || (*str)[-1] == 'O')
		return (convert_octa(get_unsigned_int(args, data, 8), data));
	else if ((*str)[-1] == 's' || (*str)[-1] == 'S')
		return (print_string(args, data));
	else if ((*str)[-1] == 'c' || (*str)[-1] == 'C')
		return (print_char(args, data));
	else if ((*str)[-1] != '\0')
		return (print_invalid_converter(data));
	(*str)--;
	return (0);
}

int			ft_printf(const char *format, ...)
{
	char	*pos;
	va_list	args;
	t_flags	data;

	data.printed_width = 0;
	pos = (char*)format;
	va_start(args, format);
	va_copy(data.ap, args);
	while (*pos)
	{
		if (*pos != '%')
		{
			write(1, pos, 1);
			data.printed_width++;
			pos++;
		}
		else if (++pos || 1)
			data.printed_width += print_conversion(&pos, &args, &data);
	}
	va_end(args);
	return (data.printed_width);
}
