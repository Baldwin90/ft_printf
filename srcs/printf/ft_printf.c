#include <unistd.h>
#include <libft.h>
#include <stddef.h>

static int	fn1(char **str, va_list *args, t_flags *data) {
	fn14(str, args, data);
	fn15(str, data);
	fn16(str, args, data);
	fn17(str, args, data);
	fn18(str, data);
	data->conversion = ((*str)++)[0];
	if ((*str)[-1] == 'd' || (*str)[-1] == 'i' || (*str)[-1] == 'D') {
		return (fn8(fn6(args, data, 10), data));
	} else if ((*str)[-1] == 'u' || (*str)[-1] == 'U') {
		return (fn8(fn7(args, data, 10), data));
	} else if ((*str)[-1] == 'p') {
		return (fn10(fn7(args, data, 16), data, 1));
	} else if ((*str)[-1] == 'x' || (*str)[-1] == 'X') {
		return (fn10(fn7(args, data, 16), data, 0));
	} else if ((*str)[-1] == 'o' || (*str)[-1] == 'O') {
		return (fn9(fn7(args, data, 8), data));
	} else if ((*str)[-1] == 's' || (*str)[-1] == 'S') {
		return (fn13(args, data));
	} else if ((*str)[-1] == 'c' || (*str)[-1] == 'C') {
		return (fn4(args, data));
	} else if ((*str)[-1] != '\0') {
		return (fn5(data));
	}
	(*str)--;
	return (0);
}

int			ft_printf(const char *format, ...) {
	char	*pos;
	va_list	args;
	t_flags	data;

	data.printed_width = 0;
	pos = (char*)format;
	va_start(args, format);
	va_copy(data.ap, args);
	while (*pos) {
		if (*pos != '%') {
			write(1, pos, 1);
			data.printed_width++;
			pos++;
		}
		else if (++pos || 1) {
			data.printed_width += fn1(&pos, &args, &data);
		}
	}
	va_end(args);
	return (data.printed_width);
}

#define PF_GET_CHAR_IDX(idx) (1<<7)|((c>>(6*(len-i-1)))&((1<<6)-1))

char		*fn2(wchar_t c) {
	int		len;
	char	*str;
	int		i;

	if (c < 128) {
		len = 1;
	} else if (c < 2048) {
		len = 2;
	} else if (c < 65536) {
		len = 3;
	} else if (c < 1114112) {
		len = 4;
	} else {
		return (NULL);
	}
	if (!(str = ft_strnew(len))) {
		return (NULL);
	}
	if (len == 1 && ((*str = (char)c) || 1)) {
		return (str);
	}
	i = -1;
	while (++i < len) {
		str[i] = PF_GET_CHAR_IDX(i);
	}
	str[0] |= (1 << 7) - (1 << (8 - len));
	return (str);
}

static int	fn3(char *str, t_flags *data) {
	int		ret;
	int		nc;

	nc = 0;
	if (*str == '\0') {
		nc = 1;
	}
	if (data->minus) {
		fn21(&str, ' ', data->width - nc, 0);
	} else if (data->zero) {
		fn21(&str, '0', data->width - nc, 1);
	} else {
		fn21(&str, ' ', data->width - nc, 1);
	}
	ret = ft_strlen(str);
	if (data->minus == 1 && nc == 1) {
		write(1, "\0", 1);
	}
	ft_putstr(str);
	if (data->minus == 0 && nc == 1) {
		write(1, "\0", 1);
	}
	free(str);
	return (ret + nc);
}

int			fn4(va_list *args, t_flags *data) {
	char	*str;

	if (data->length == 3 || data->conversion == 'C') {
		str = fn2(va_arg(*args, wchar_t));
	}
	else {
		str = (char*)malloc(sizeof(*str) * 2);
		if (!str) {
			return (0);
		}
		str[0] = (char)va_arg(*args, int);
		str[1] = '\0';
	}
	return (fn3(str, data));
}

int			fn5(t_flags *data) {
	char	*str;

	str = (char*)malloc(sizeof(*str) * 2);
	if (!str) {
		return (0);
	}
	str[0] = data->conversion;
	str[1] = '\0';
	return (fn3(str, data));
}

char		*fn6(va_list *args, t_flags *data, int base) {
	intmax_t	a;

	if (data->length == 3 || data->conversion == 'D') {
		a = va_arg(*args, long);
	} else if (data->length == 1) {
		a = (char)va_arg(*args, int);
	} else if (data->length == 2) {
		a = (short)va_arg(*args, int);
	} else if (data->length == 4) {
		a = va_arg(*args, long long);
	} else if (data->length == 5) {
		a = va_arg(*args, intmax_t);
	} else if (data->length == 6) {
		a = va_arg(*args, ssize_t);
	} else if (data->length == 8) {
		a = va_arg(*args, ptrdiff_t);
	} else {
		a = va_arg(*args, int);
	}
	data->sign = 1;
	if (a < 0) {
		data->sign = -1;
	}
	data->num = (uintmax_t)(data->sign * a);
	return (ft_llutoa_base(data->num, base));
}

char		*fn7(va_list *args, t_flags *data, int base) {
	if (data->length == 5 || data->conversion == 'p') {
		data->num = va_arg(*args, uintmax_t);
	} else if (data->length == 3 || data->conversion == 'U' || data->conversion == 'O') {
		data->num = va_arg(*args, unsigned long);
	} else if (data->length == 1) {
		data->num = (unsigned char)va_arg(*args, unsigned int);
	} else if (data->length == 2) {
		data->num = (unsigned short)va_arg(*args, unsigned int);
	} else if (data->length == 4) {
		data->num = va_arg(*args, unsigned long long);
	} else if (data->length == 6) {
		data->num = va_arg(*args, size_t);
	} else {
		data->num = va_arg(*args, unsigned int);
	}
	data->sign = 0;
	return (ft_llutoa_base(data->num, base));
}

int			fn8(char *str, t_flags *data) {
	int		ret;

	if (data->num == 0 && data->precision == 0) {
		fn19(&str);
	}
	fn21(&str, '0', data->precision, 1);
	if (data->zero == 1 && data->minus == 0 && data->precision < 0) {
		fn21(&str, '0', data->width - 1, 1);
		if (data->sign == 0 || (data->plus == 0
			&& data->space == 0 && data->sign == 1))
			fn21(&str, '0', data->width, 1);
	}
	if (data->sign == -1) {
		fn22(&str, "-", str);
	} else if (data->plus == 1 && data->sign == 1) {
		fn22(&str, "+", str);
	} else if (data->space == 1 && data->sign == 1) {
		fn22(&str, " ", str);
	}
	if (data->minus == 1) {
		fn21(&str, ' ', data->width, 0);
	}
	fn21(&str, ' ', data->width, 1);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			fn9(char *str, t_flags *data) {
	int		ret;

	if (data->num == 0 && data->precision == 0) {
		fn19(&str);
	}
	fn21(&str, '0', data->precision, 1);
	if (data->zero == 1 && data->minus == 0 && data->precision < 0) {
		if (data->hashtag == 1 && data->num != 0) {
			fn21(&str, '0', data->width - 1, 1);
		} else {
			fn21(&str, '0', data->width, 1);
		}
	}
	if (data->hashtag == 1 && *str != '0') {
		fn22(&str, "0", str);
	}
	if (data->minus == 1) {
		fn21(&str, ' ', data->width, 0);
	} else {
		fn21(&str, ' ', data->width, 1);
	}
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			fn10(char *str, t_flags *data, int fmt) {
	int		ret;

	if (data->num == 0 && data->precision == 0) {
		fn19(&str);
	}
	fn21(&str, '0', data->precision, 1);
	if (data->zero == 1 && data->minus == 0 && data->precision < 0) {
		if ((data->hashtag == 1 && data->num != 0) || fmt == 1) {
			fn21(&str, '0', data->width - 2, 1);
		} else {
			fn21(&str, '0', data->width, 1);
		}
	}
	if ((data->hashtag == 1 && data->num != 0) || fmt == 1) {
		fn22(&str, "0x", str);
	}
	if (data->minus == 1) {
		fn21(&str, ' ', data->width, 0);
	} else {
		fn21(&str, ' ', data->width, 1);
	}
	if (data->conversion >= 'A' && data->conversion <= 'Z') {
		ft_strupcase(str);
	}
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

static void	fn11(char **str, int len) {
	int		nlen;
	int		wlen;
	char	*dup;

	if (len < 0 || len >= (int)ft_strlen(*str))
		return ;
	nlen = 0;
	while ((*str)[nlen] && nlen <= len) {
		wlen = 1;
		if (((unsigned char)(*str)[nlen] & 240) == 240) {
			wlen = 4;
		} else if (((unsigned char)(*str)[nlen] & 224) == 224) {
			wlen = 3;
		} else if (((unsigned char)(*str)[nlen] & 192) == 192) {
			wlen = 2;
		}
		if (nlen + wlen > len) {
			break ;
		}
		nlen += wlen;
	}
	(*str)[nlen] = '\0';
	dup = ft_strdup(*str);
	free(*str);
	*str = dup;
}

static int	fn12(char *str, t_flags *data) {
	int		ret;

	fn11(&str, data->precision);
	if (data->minus == 1) {
		fn21(&str, ' ', data->width, 0);
	} else if (data->zero == 1) {
		fn21(&str, '0', data->width, 1);
	} else {
		fn21(&str, ' ', data->width, 1);
	}
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			fn13(va_list *args, t_flags *data) {
	char	*str;
	char	*tmp;
	wchar_t	*wstr;

	if (data->length == 3 || data->conversion == 'S') {
		if (!(wstr = va_arg(*args, wchar_t*))) {
			return (fn12(ft_strdup("(null)"), data));
		}
		if (!(str = (char*)malloc(sizeof(*str)))) {
			return (0);
		}
		str[0] = '\0';
		while (*wstr) {
			tmp = fn2(wstr[0]);
			fn22(&str, str, tmp);
			free(tmp);
			wstr++;
		}
	} else {
		str = va_arg(*args, char*);
		return (fn12(str ? ft_strdup(str) : ft_strdup("(null)"), data));
	}
	return (fn12(str, data));
}

void	fn14(char **pos, va_list *args, t_flags *data) {
	int		i;
	int		argnum;

	i = 0;
	argnum = 0;
	while ((*pos)[i] >= '0' && (*pos)[i] <= '9') {
		argnum = argnum * 10 + (*pos)[i] - '0';
		i++;
	}
	if ((*pos)[i] != '$') {
		return ;
	}
	va_copy(*args, data->ap);
	while (--argnum) {
		va_arg(*args, int);
	}
	(*pos) += i + 1;
}

void	fn15(char **pos, t_flags *data) {
	data->hashtag = 0;
	data->zero = 0;
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->last_pos = 0;
	while (**pos == '#' || **pos == '0' || **pos == '-' || **pos == '+' ||
			**pos == ' ' || **pos == '\'') {
		if (**pos == '#') {
			data->hashtag = 1;
		} else if (**pos == '0') {
			data->zero = 1;
		} else if (**pos == '-') {
			data->minus = 1;
		} else if (**pos == '+') {
			data->plus = 1;
		} else if (**pos == ' ') {
			data->space = 1;
		} else if (**pos == '\'') {
			data->last_pos = 1;
		}
		(*pos)++;
	}
}

void	fn16(char **pos, va_list *args, t_flags *data) {
	data->width = 0;
	while ((**pos >= '0' && **pos <= '9') || **pos == '*') {
		if (**pos == '*') {
			data->width = va_arg(*args, int);
			if (data->width < 0) {
				data->width *= -1;
				data->minus = 1;
			}
		}
		else if ((*pos)[-1] >= '0' && (*pos)[-1] <= '9') {
			data->width = data->width * 10 + **pos - '0';
		}
		else {
			data->width = **pos - '0';
		}
		(*pos)++;
	}
}

void	fn17(char **pos, va_list *args, t_flags *data) {
	data->precision = -6;
	if (**pos != '.')
		return ;
	data->precision = 0;
	(*pos)++;
	if (**pos == '*')
		data->precision = va_arg(*args, int);
	else {
		while (**pos >= '0' && **pos <= '9') {
			data->precision = data->precision * 10 + **pos - '0';
			(*pos)++;
		}
	}
	while ((**pos >= '0' && **pos <= '9') || **pos == '*') {
		(*pos)++;
	}
}

void	fn18(char **pos, t_flags *data) {
	data->length = 0;
	if ((*pos)[0] == 'h' && (*pos)[1] == 'h') {
		data->length = 1;
	} else if ((*pos)[0] == 'h') {
		data->length = 2;
	} else if ((*pos)[0] == 'l' && (*pos)[1] != 'l') {
		data->length = 3;
	} else if ((*pos)[0] == 'l') {
		data->length = 4;
	} else if ((*pos)[0] == 'j') {
		data->length = 5;
	} else if ((*pos)[0] == 'z') {
		data->length = 6;
	} else if ((*pos)[0] == 'L') {
		data->length = 7;
	} else if ((*pos)[0] == 't') {
		data->length = 8;
	}
	if (data->length == 1 || data->length == 4) {
		(*pos) += 2;
	} else if (data->length > 0) {
		(*pos)++;
	}
}

void	fn19(char **str) {
	free(*str);
	*str = (char*)malloc(sizeof(**str));
	(*str)[0] = '\0';
}

char	*fn20(char c, int len) {
	char	*result;

	if (!(result = ft_strnew(len))) {
		return (NULL);
	}
	ft_memset(result, c, len);
	return (result);
}

void	fn21(char **str, char c, int len, char is_prepended) {
	char	*repeating_chars;

	len -= ft_strlen(*str);
	if (!str || !*str || len <= 0) {
		return ;
	}
	repeating_chars = fn20(c, len);
	if (is_prepended) {
		fn22(str, repeating_chars, *str);
	}
	else {
		fn22(str, *str, repeating_chars);
	}
	free(repeating_chars);
}

void	fn22(char **target, char *dst, char *src) {
	int		dlen;
	int		slen;
	char	*result;

	if (!target || !*target || !dst || !src)
		return ;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (!(result = ft_strnew(dlen + slen))) {
		free(*target);
		*target = NULL;
		return ;
	}
	result[dlen + slen] = '\0';
	while (slen--) {
		result[dlen + slen] = src[slen];
	}
	while (dlen--) {
		result[dlen] = dst[dlen];
	}
	free(*target);
	*target = result;
}
