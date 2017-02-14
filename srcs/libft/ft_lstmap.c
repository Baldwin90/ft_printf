/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:40:48 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:40:49 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (f(lst));
	l = ft_lstmap(lst->next, f);
	ft_lstadd(&l, f(lst));
	return (l);
}
