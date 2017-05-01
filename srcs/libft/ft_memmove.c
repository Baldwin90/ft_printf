/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:41:51 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:41:52 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*cast_src;
	char			*cast_dst;

	cast_src = (char *)src;
	cast_dst = (char *)dst;
	if (len == 0 || dst == src)
		return (dst);
	i = 0;
	if ((unsigned long)dst < (unsigned long)src)
	{
		while (i < len)
		{
			cast_dst[i] = cast_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			cast_dst[i] = cast_src[i];
	}
	return (dst);
}
