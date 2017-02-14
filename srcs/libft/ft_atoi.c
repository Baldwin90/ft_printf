/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:38:16 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:38:22 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (*nptr && (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		sign = 44 - *nptr;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if ((num / 922337203685477580U == 1 && (*nptr - '0' >= 8 ||
			num % 922337203685477580U >= 1)) || (num / 922337203685477580U > 1))
			return ((-sign - 1) / 2);
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	num *= sign;
	return (num);
}
