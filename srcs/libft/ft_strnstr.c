/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:46:21 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:46:22 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_str_comp(const char *big, const char *little)
{
	int	i;

	i = 0;
	while (little[i])
	{
		if (big[i] != little[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && (i + len <= n))
	{
		if (big[i] == little[0])
			if (my_str_comp((big + i), little))
				return ((char *)&(big[i]));
		i++;
	}
	return (0);
}
