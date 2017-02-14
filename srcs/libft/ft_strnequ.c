/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:45:59 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:46:00 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		i = 0;
		while ((i + 1 < n) && s1[i] && s2[i] && (s1[i] == s2[i]))
			i++;
		return ((unsigned char)s1[i] == (unsigned char)s2[i]);
	}
	return (0);
}
