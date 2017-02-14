/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:46:54 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:46:55 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int	start_point;
	int	end_point;

	if (!s)
		return (0);
	if (!(s[0] == '\0'))
	{
		start_point = 0;
		while (is_white_space(s[start_point]))
			start_point++;
		end_point = ft_strlen(s);
		while ((end_point > start_point) && ((s[end_point] == '\0') || \
		(is_white_space(s[end_point]))))
			end_point--;
		return (ft_strsub(s, start_point, (++end_point - start_point)));
	}
	return (ft_strnew(1));
}
