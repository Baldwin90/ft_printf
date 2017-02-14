/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:39:38 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:39:39 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	static char	digits[16];
	int			i;
	char		*str;
	char		polar;

	if (!n)
		return ("0");
	i = -1;
	while (++i < 16)
		digits[i] = 0;
	str = &(digits[15]);
	polar = (n < 0) ? -1 : 1;
	while (n)
	{
		*(--str) = ((n % 10) * polar) + '0';
		n /= 10;
	}
	if (polar == -1)
		*(--str) = '-';
	return (str);
}
