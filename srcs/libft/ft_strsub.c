/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:46:47 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:46:48 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = start;
	while (i < len)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (s && is_valid(s, start, len) && (ret = ft_strnew(len)))
	{
		i = 0;
		while (i < len)
		{
			ret[i] = s[start + i];
			i++;
		}
		return (ret);
	}
	return (0);
}
