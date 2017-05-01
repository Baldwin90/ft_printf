/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:45:15 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:45:16 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	if (s && (ret = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			ret[i] = f(s[i]);
			i++;
		}
		return (ret);
	}
	return (0);
}
