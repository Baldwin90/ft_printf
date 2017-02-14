/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:46:36 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:46:37 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	delim_count(char const *s, char c)
{
	int	i;
	int	count;
	int	already_seen;

	already_seen = 0;
	i = 0;
	count = 0;
	already_seen = 1;
	while (s[i])
	{
		if (s[i] == c)
			already_seen = 1;
		else
		{
			if (already_seen)
			{
				count++;
				already_seen = 0;
			}
		}
		i++;
	}
	return (count);
}

static int	*start_word_indices(char const *s, char c, int *indices)
{
	int	i;
	int	count;
	int	already_seen;

	already_seen = 0;
	i = 0;
	count = 0;
	already_seen = 1;
	while (s[i])
	{
		if (s[i] == c)
			already_seen = 1;
		else
		{
			if (already_seen)
			{
				indices[count++] = i;
				already_seen = 0;
			}
		}
		i++;
	}
	return (indices);
}

static int	word_length(char const *s, char c, int i)
{
	int	start;

	start = i;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i - start);
}

static char	*alloc_word(char const *s, char c, int i)
{
	char	*output;
	int		j;

	j = 0;
	output = ft_strnew(word_length(s, c, i));
	while (s[i] && s[i] != c)
		output[j++] = s[i++];
	return (output);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**output;
	int		count;
	int		*indices;
	int		i;

	if (!s)
		return (0);
	count = delim_count(s, c);
	if (!(indices = (int *)malloc(sizeof(int) * (count))))
		return (0);
	indices = start_word_indices(s, c, indices);
	if (!(output = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	while (i < count)
	{
		output[i] = alloc_word(s, c, indices[i]);
		i++;
	}
	free(indices);
	return (output);
}
