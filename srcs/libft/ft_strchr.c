/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:43:35 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:43:36 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	int		i;

	target = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return ((char *)&(s[i]));
		i++;
	}
	if (target == 0)
		return ((char *)&(s[i]));
	return (0);
}
