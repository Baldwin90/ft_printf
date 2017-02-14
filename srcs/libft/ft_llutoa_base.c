/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:39:27 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:39:28 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llutoa_base(unsigned long long n, int base)
{
	char	*str;
	char	*bases;
	char	*head;

	bases = "0123456789abcdef";
	if (!(head = ft_memalloc(64)))
		return (0);
	str = head + 63;
	if (!n)
		*(--str) = '0';
	while (n)
	{
		*(--str) = bases[n % base];
		n /= base;
	}
	str = ft_strdup(str);
	free(head);
	return (str);
}
