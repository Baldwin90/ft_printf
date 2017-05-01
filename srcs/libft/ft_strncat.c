/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:06:20 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/08/15 12:06:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char	*i;

	i = dest - 1;
	while (*(++i))
		;
	while (*src && nb--)
		*i++ = *src++;
	*i = 0;
	return (dest);
}
