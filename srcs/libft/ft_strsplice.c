/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:42:49 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:42:50 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsplice(char **head, size_t tgt, size_t amt, char *src)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(*head) + ft_strlen(src) - amt)))
		return (0);
	ft_memcpy(str, *head, tgt);
	ft_strcpy(str + tgt, src);
	ft_strcpy(str + tgt + ft_strlen(src), *head + amt + tgt);
	free(*head);
	*head = str;
	return (ft_strlen(src));
}
