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
#include <stddef.h>
#define PF_GET_CHAR_IDX(idx) (1<<7)|((c>>(6*(len-i-1)))&((1<<6)-1))
#define AA  static int fn1(char **str, va_list *args, t_flags *data) {
#define AB AA fn14(str, args, data); fn15(str, data); fn16(str, args, data);
#define AC AB fn17(str, args, data); fn18(str, data); data->conversion =
#define AD AC ((*str)++)[0]; if ((*str)[-1] == 'd' || (*str)[-1] == 'i' ||
#define AE AD (*str)[-1] == 'D') { return (fn8(fn6(args, data, 10), data)); }
#define AF AE else if ((*str)[-1] == 'u' || (*str)[-1] == 'U') { return
#define AG AF (fn8(fn7(args, data, 10), data)); } else if ((*str)[-1] == 'p') {
#define AH AG return (fn10(fn7(args, data, 16), data, 1)); } else if
#define AI AH ((*str)[-1] == 'x' || (*str)[-1] == 'X') { return (fn10(fn7(args,
#define AJ AI data, 16), data, 0)); } else if ((*str)[-1] == 'o' || (*str)[-1]
#define AK AJ == 'O') { return (fn9(fn7(args, data, 8), data)); } else if
#define AL AK ((*str)[-1] == 's' || (*str)[-1] == 'S') { return (fn13(args,
#define AM AL data)); } else if ((*str)[-1] == 'c' || (*str)[-1] == 'C') {
#define AN AM return (fn4(args, data)); } else if ((*str)[-1] != '\0') { return
#define AO AN (fn5(data)); } (*str)--; return (0); } int ft_printf(const char
#define AP AO *format, ...) { char *pos; va_list args; t_flags data;
#define AQ AP data.printed_width = 0; pos = (char*)format; va_start(args,
#define AR AQ format); va_copy(data.ap, args); while (*pos) { if (*pos != '%')
#define AS AR { write(1, pos, 1); data.printed_width++; pos++; } else if (++pos
#define AT AS || 1) { data.printed_width += fn1(&pos, &args, &data); } }
#define AU AT va_end(args); return (data.printed_width); } char *fn2(wchar_t c)
#define AV AU { int len; char *str; int i; if (c < 128) { len = 1; } else if (c
#define AW AV < 2048) { len = 2; } else if (c < 65536) { len = 3; } else if (c
#define AX AW < 1114112) { len = 4; } else { return (NULL); } if (!(str =
#define AY AX ft_strnew(len))) { return (NULL); } if (len == 1 && ((*str =
#define AZ AY (char)c) || 1)) { return (str); } i = -1; while (++i < len) {
#define BA AZ str[i] = PF_GET_CHAR_IDX(i); } str[0] |= (1 << 7) - (1 << (8 -
#define BB BA len)); return (str); } static int fn3(char *str, t_flags *data) {
#define BC BB int ret; int nc; nc = 0; if (*str == '\0') { nc = 1; } if
#define BD BC (data->minus) { fn21(&str, ' ', data->width - nc, 0); } else if
#define BE BD (data->zero) { fn21(&str, '0', data->width - nc, 1); } else {
#define BF BE fn21(&str, ' ', data->width - nc, 1); } ret = ft_strlen(str); if
#define BG BF (data->minus == 1 && nc == 1) { write(1, "\0", 1); }
#define BH BG ft_putstr(str); if (data->minus == 0 && nc == 1) { write(1, "\0",
#define BI BH 1); } free(str); return (ret + nc); } int fn4(va_list *args,
#define BJ BI t_flags *data) { char *str; if (data->length == 3 ||
#define BK BJ data->conversion == 'C') { str = fn2(va_arg(*args, wchar_t)); }
#define BL BK else { str = (char*)malloc(sizeof(*str) * 2); if (!str) { return
#define BM BL (0); } str[0] = (char)va_arg(*args, int); str[1] = '\0'; } return
#define BN BM (fn3(str, data)); } int fn5(t_flags *data) { char *str; str =
#define BO BN (char*)malloc(sizeof(*str) * 2); if (!str) { return (0); } str[0]
#define BP BO = data->conversion; str[1] = '\0'; return (fn3(str, data)); }
#define BQ BP char *fn6(va_list *args, t_flags *data, int base) { intmax_t a;
#define BR BQ if (data->length == 3 || data->conversion == 'D') { a =
#define BS BR va_arg(*args, long); } else if (data->length == 1) { a =
#define BT BS (char)va_arg(*args, int); } else if (data->length == 2) { a =
#define BU BT (short)va_arg(*args, int); } else if (data->length == 4) { a =
#define BV BU va_arg(*args, long long); } else if (data->length == 5) { a =
#define BW BV va_arg(*args, intmax_t); } else if (data->length == 6) { a =
#define BX BW va_arg(*args, ssize_t); } else if (data->length == 8) { a =
#define BY BX va_arg(*args, ptrdiff_t); } else { a = va_arg(*args, int); }
#define BZ BY data->sign = 1; if (a < 0) { data->sign = -1; } data->num =
#define CA BZ (uintmax_t)(data->sign * a); return (ft_llutoa_base(data->num,
#define CB CA base)); } char *fn7(va_list *args, t_flags *data, int base) { if
#define CC CB (data->length == 5 || data->conversion == 'p') { data->num =
#define CD CC va_arg(*args, uintmax_t); } else if (data->length == 3 ||
#define CE CD data->conversion == 'U' || data->conversion == 'O') { data->num =
#define CF CE va_arg(*args, unsigned long); } else if (data->length == 1) {
#define CG CF data->num = (unsigned char)va_arg(*args, unsigned int); } else if
#define CH CG (data->length == 2) { data->num = (unsigned short)va_arg(*args,
#define CI CH unsigned int); } else if (data->length == 4) { data->num =
#define CJ CI va_arg(*args, unsigned long long); } else if (data->length == 6)
#define CK CJ { data->num = va_arg(*args, size_t); } else { data->num =
#define CL CK va_arg(*args, unsigned int); } data->sign = 0; return
#define CM CL (ft_llutoa_base(data->num, base)); } int fn8(char *str, t_flags
#define CN CM *data) { int ret; if (data->num == 0 && data->precision == 0) {
#define CO CN fn19(&str); } fn21(&str, '0', data->precision, 1); if (data->zero
#define CP CO == 1 && data->minus == 0 && data->precision < 0) { fn21(&str,
#define CQ CP '0', data->width - 1, 1); if (data->sign == 0 || (data->plus == 0
#define CR CQ && data->space == 0 && data->sign == 1)) fn21(&str, '0',
#define CS CR data->width, 1); } if (data->sign == -1) { fn22(&str, "-", str);
#define CT CS } else if (data->plus == 1 && data->sign == 1) { fn22(&str, "+",
#define CU CT str); } else if (data->space == 1 && data->sign == 1) {
#define CV CU fn22(&str, " ", str); } if (data->minus == 1) { fn21(&str, ' ',
#define CW CV data->width, 0); } fn21(&str, ' ', data->width, 1); ret =
#define CX CW ft_strlen(str); ft_putstr(str); free(str); return (ret); } int
#define CY CX fn9(char *str, t_flags *data) { int ret; if (data->num == 0 &&
#define CZ CY data->precision == 0) { fn19(&str); } fn21(&str, '0',
#define DA CZ data->precision, 1); if (data->zero == 1 && data->minus == 0 &&
#define DB DA data->precision < 0) { if (data->hashtag == 1 && data->num != 0)
#define DC DB { fn21(&str, '0', data->width - 1, 1); } else { fn21(&str, '0',
#define DD DC data->width, 1); } } if (data->hashtag == 1 && *str != '0') {
#define DE DD fn22(&str, "0", str); } if (data->minus == 1) { fn21(&str, ' ',
#define DF DE data->width, 0); } else { fn21(&str, ' ', data->width, 1); } ret
#define DG DF = ft_strlen(str); ft_putstr(str); free(str); return (ret); } int
#define DH DG fn10(char *str, t_flags *data, int fmt) { int ret; if (data->num
#define DI DH == 0 && data->precision == 0) { fn19(&str); } fn21(&str, '0',
#define DJ DI data->precision, 1); if (data->zero == 1 && data->minus == 0 &&
#define DK DJ data->precision < 0) { if ((data->hashtag == 1 && data->num != 0)
#define DL DK || fmt == 1) { fn21(&str, '0', data->width - 2, 1); } else {
#define DM DL fn21(&str, '0', data->width, 1); } } if ((data->hashtag == 1 &&
#define DN DM data->num != 0) || fmt == 1) { fn22(&str, "0x", str); } if
#define DO DN (data->minus == 1) { fn21(&str, ' ', data->width, 0); } else {
#define DP DO fn21(&str, ' ', data->width, 1); } if (data->conversion >= 'A' &&
#define DQ DP data->conversion <= 'Z') { ft_strupcase(str); } ret =
#define DR DQ ft_strlen(str); ft_putstr(str); free(str); return (ret); } static
#define DS DR void fn11(char **str, int len) { int nlen; int wlen; char *dup;
#define DT DS if (len < 0 || len >= (int)ft_strlen(*str)) return ; nlen = 0;
#define DU DT while ((*str)[nlen] && nlen <= len) { wlen = 1; if (((unsigned
#define DV DU char)(*str)[nlen] & 240) == 240) { wlen = 4; } else if
#define DW DV (((unsigned char)(*str)[nlen] & 224) == 224) { wlen = 3; } else
#define DX DW if (((unsigned char)(*str)[nlen] & 192) == 192) { wlen = 2; } if
#define DY DX (nlen + wlen > len) { break ; } nlen += wlen; } (*str)[nlen] =
#define DZ DY '\0'; dup = ft_strdup(*str); free(*str); *str = dup; } static int
#define EA DZ fn12(char *str, t_flags *data) { int ret; fn11(&str,
#define EB EA data->precision); if (data->minus == 1) { fn21(&str, ' ',
#define EC EB data->width, 0); } else if (data->zero == 1) { fn21(&str, '0',
#define ED EC data->width, 1); } else { fn21(&str, ' ', data->width, 1); } ret
#define EE ED = ft_strlen(str); ft_putstr(str); free(str); return (ret); } int
#define EF EE fn13(va_list *args, t_flags *data) { char *str; char *tmp;
#define EG EF wchar_t *wstr; if (data->length == 3 || data->conversion == 'S')
#define EH EG { if (!(wstr = va_arg(*args, wchar_t*))) { return
#define EI EH (fn12(ft_strdup("(null)"), data)); } if (!(str =
#define EJ EI (char*)malloc(sizeof(*str)))) { return (0); } str[0] = '\0';
#define EK EJ while (*wstr) { tmp = fn2(wstr[0]); fn22(&str, str, tmp);
#define EL EK free(tmp); wstr++; } } else { str = va_arg(*args, char*); return
#define EM EL (fn12(str ? ft_strdup(str) : ft_strdup("(null)"), data)); }
#define EN EM return (fn12(str, data)); } void fn14(char **pos, va_list *args,
#define EO EN t_flags *data) { int i; int argnum; i = 0; argnum = 0; while
#define EP EO ((*pos)[i] >= '0' && (*pos)[i] <= '9') { argnum = argnum * 10 +
#define EQ EP (*pos)[i] - '0'; i++; } if ((*pos)[i] != '$') { return ; }
#define ER EQ va_copy(*args, data->ap); while (--argnum) { va_arg(*args, int);
#define ES ER } (*pos) += i + 1; } void fn15(char **pos, t_flags *data) {
#define ET ES data->hashtag = 0; data->zero = 0; data->minus = 0; data->plus =
#define EU ET 0; data->space = 0; data->last_pos = 0; while (**pos == '#' ||
#define EV EU **pos == '0' || **pos == '-' || **pos == '+' || **pos == ' ' ||
#define EW EV **pos == '\'') { if (**pos == '#') { data->hashtag = 1; } else if
#define EX EW (**pos == '0') { data->zero = 1; } else if (**pos == '-') {
#define EY EX data->minus = 1; } else if (**pos == '+') { data->plus = 1; }
#define EZ EY else if (**pos == ' ') { data->space = 1; } else if (**pos ==
#define FA EZ '\'') { data->last_pos = 1; } (*pos)++; } } void fn16(char **pos,
#define FB FA va_list *args, t_flags *data) { data->width = 0; while ((**pos >=
#define FC FB '0' && **pos <= '9') || **pos == '*') { if (**pos == '*') {
#define FD FC data->width = va_arg(*args, int); if (data->width < 0) {
#define FE FD data->width *= -1; data->minus = 1; } } else if ((*pos)[-1] >=
#define FF FE '0' && (*pos)[-1] <= '9') { data->width = data->width * 10 +
#define FG FF **pos - '0'; } else { data->width = **pos - '0'; } (*pos)++; } }
#define FH FG void fn17(char **pos, va_list *args, t_flags *data) {
#define FI FH data->precision = -6; if (**pos != '.') return ; data->precision
#define FJ FI = 0; (*pos)++; if (**pos == '*') data->precision = va_arg(*args,
#define FK FJ int); else { while (**pos >= '0' && **pos <= '9') {
#define FL FK data->precision = data->precision * 10 + **pos - '0'; (*pos)++; }
#define FM FL } while ((**pos >= '0' && **pos <= '9') || **pos == '*') {
#define FN FM (*pos)++; } } void fn18(char **pos, t_flags *data) { data->length
#define FO FN = 0; if ((*pos)[0] == 'h' && (*pos)[1] == 'h') { data->length =
#define FP FO 1; } else if ((*pos)[0] == 'h') { data->length = 2; } else if
#define FQ FP ((*pos)[0] == 'l' && (*pos)[1] != 'l') { data->length = 3; } else
#define FR FQ if ((*pos)[0] == 'l') { data->length = 4; } else if ((*pos)[0] ==
#define FS FR 'j') { data->length = 5; } else if ((*pos)[0] == 'z') {
#define FT FS data->length = 6; } else if ((*pos)[0] == 'L') { data->length =
#define FU FT 7; } else if ((*pos)[0] == 't') { data->length = 8; } if
#define FV FU (data->length == 1 || data->length == 4) { (*pos) += 2; } else if
#define FW FV (data->length > 0) { (*pos)++; } } void fn19(char **str) {
#define FX FW free(*str); *str = (char*)malloc(sizeof(**str)); (*str)[0] =
#define FY FX '\0'; } char *fn20(char c, int len) { char *result; if (!(result
#define FZ FY = ft_strnew(len))) { return (NULL); } ft_memset(result, c, len);
#define GA FZ return (result); } void fn21(char **str, char c, int len, char
#define GB GA is_prepended) { char *repeating_chars; len -= ft_strlen(*str); if
#define GC GB (!str || !*str || len <= 0) { return ; } repeating_chars =
#define GD GC fn20(c, len); if (is_prepended) { fn22(str, repeating_chars,
#define GE GD *str); } else { fn22(str, *str, repeating_chars); }
#define GF GE free(repeating_chars); } void fn22(char **target, char *dst, char
#define GG GF *src) { int dlen; int slen; char *result; if (!target || !*target
#define GH GG || !dst || !src) return ; dlen = ft_strlen(dst); slen =
#define GI GH ft_strlen(src); if (!(result = ft_strnew(dlen + slen))) {
#define GJ GI free(*target); *target = NULL; return ; } result[dlen + slen] =
#define GK GJ '\0'; while (slen--) { result[dlen + slen] = src[slen]; } while
#define GL GK (dlen--) { result[dlen] = dst[dlen]; } free(*target); *target =
#define GM GL result; }
#define MAIN GM

MAIN;
