/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:41:26 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:41:27 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_src;
	unsigned char	*cast_dst;
	unsigned char	ch;

	ch = c;
	i = 0;
	cast_src = (unsigned char *)src;
	cast_dst = (unsigned char *)dst;
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		if (cast_src[i] == ch)
			return (dst + (++i));
		i++;
	}
	return (0);
}
