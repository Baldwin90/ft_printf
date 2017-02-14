/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:44:47 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:44:48 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*ret;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		if ((ret = ft_strnew(s1_len + s2_len)))
		{
			i = -1;
			while (++i < s1_len)
				ret[i] = s1[i];
			i = 0;
			while (i < s2_len)
			{
				ret[s1_len + i] = s2[i];
				i++;
			}
			return (ret);
		}
	}
	return (0);
}
