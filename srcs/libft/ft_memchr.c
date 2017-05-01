/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:55:35 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/02 19:55:39 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;
	unsigned char	ch;

	ch = c;
	i = 0;
	cast_s = (unsigned char *)s;
	while (i < n)
	{
		if (cast_s[i] == ch)
			return (cast_s + i);
		i++;
	}
	return (0);
}
