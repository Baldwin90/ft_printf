/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:47:15 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:47:16 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

typedef struct	s_flags
{
	int			hashtag;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			last_pos;
	int			width;
	int			precision;
	int			length;
	int			sign;
	uintmax_t	num;
	char		conversion;
	va_list		ap;
	int			printed_width;
}				t_flags;

# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) > (b) ? (b) : (a))

int				ft_printf(const char *format, ...);

void			fn14(char **pos, va_list *args, t_flags *data);
void			fn15(char **pos, t_flags *data);
void			fn16(char **pos, va_list *args, t_flags *data);
void			fn17(char **pos, va_list *args, t_flags *data);
void			fn18(char **pos, t_flags *data);

void			fn21(char **str, char c, int len, char is_prep);
void			fn22(char **target, char *dst, char *src);
char			*fn2(wchar_t c);
char			*fn6(va_list *args, t_flags *data, int base);
char			*fn7(va_list *args, t_flags *data, int base);

int				fn10(char *str, t_flags *data, int fmt);
int				fn9(char *str, t_flags *data);
int				fn8(char *str, t_flags *data);

int				fn13(va_list *args, t_flags *data);
int				fn4(va_list *args, t_flags *data);
int				fn5(t_flags *data);
void			fn19(char **str);

typedef struct	s_l
{
	void		*content;
	size_t		content_size;
	struct s_l	*next;
}				t_list;

int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strtrim(char const *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strstr(const char *big, const char *little);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t n);
char			*ft_strnew(size_t size);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, const char *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
void			ft_strdel(char **as);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strclr(char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_memdel(void **ap);
char			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
double			ft_sqrt(double n);
int				ft_ceil(double n);
char			*ft_strndup(const char *s1, size_t n);
int				ft_strcontains(char const *s, char c);
size_t			ft_strclen(const char *s, char c);
size_t			ft_strsplice(char **head, size_t tgt, size_t amt, char *src);
void			*ft_memjoin(void const *s1, void const *s2, int dlen, int slen);
char			*ft_llutoa_base(unsigned long long n, int base);
void			ft_strupcase(char *str);
#endif
