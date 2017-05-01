/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:45:20 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:45:21 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (s && (ret = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			ret[i] = f(i, s[i]);
			i++;
		}
		return (ret);
	}
	return (0);
}
