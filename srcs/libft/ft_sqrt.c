/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:39:18 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:39:18 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double n)
{
	double	a;
	double	b;
	double	cache;

	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	a = n / 2;
	cache = a;
	while (1)
	{
		b = n / a;
		a = (a + b) / 2;
		if (a - cache == 0)
			return (a);
		cache = a;
	}
	return (-1);
}
