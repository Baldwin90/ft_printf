/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:46:42 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:46:42 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	my_str_comp(const char *big, const char *little)
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

char		*ft_strstr(const char *big, const char *little)
{
	int	len;
	int	i;

	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == little[0])
			if (my_str_comp((big + i), little))
				return ((char *)&(big[i]));
		i++;
	}
	return (0);
}
