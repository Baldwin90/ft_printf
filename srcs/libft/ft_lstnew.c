/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:41:02 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:41:03 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;
	void	*c;

	if (!(c = (void*)ft_memalloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		c = NULL;
		content_size = 0;
	}
	else
		c = ft_memcpy(c, content, content_size);
	if (!(newlst = (t_list*)malloc(sizeof(newlst) * content_size)))
	{
		free(c);
		return (NULL);
	}
	newlst->content = c;
	newlst->content_size = content_size;
	newlst->next = NULL;
	return (newlst);
}
