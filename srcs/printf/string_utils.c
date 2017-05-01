/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:08:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/21 14:08:53 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	clear_string(char **str)
{
	free(*str);
	*str = (char*)malloc(sizeof(**str));
	(*str)[0] = '\0';
}

char	*new_repeating_string(char c, int len)
{
	char	*result;

	if (!(result = ft_strnew(len)))
		return (NULL);
	ft_memset(result, c, len);
	return (result);
}

void	join_repeating_char(char **str, char c, int len, char is_prepended)
{
	char	*repeating_chars;

	len -= ft_strlen(*str);
	if (!str || !*str || len <= 0)
		return ;
	repeating_chars = new_repeating_string(c, len);
	if (is_prepended)
		join_str_target(str, repeating_chars, *str);
	else
		join_str_target(str, *str, repeating_chars);
	free(repeating_chars);
}

void	join_str_target(char **target, char *dst, char *src)
{
	int		dlen;
	int		slen;
	char	*result;

	if (!target || !*target || !dst || !src)
		return ;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (!(result = ft_strnew(dlen + slen)))
	{
		free(*target);
		*target = NULL;
		return ;
	}
	result[dlen + slen] = '\0';
	while (slen--)
		result[dlen + slen] = src[slen];
	while (dlen--)
		result[dlen] = dst[dlen];
	free(*target);
	*target = result;
}
