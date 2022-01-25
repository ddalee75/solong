/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:43:16 by chilee            #+#    #+#             */
/*   Updated: 2021/12/15 13:43:11 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*page_tmp;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	if (!newlst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		page_tmp = ft_lstnew((*f)(lst->content));
		if (!page_tmp)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, page_tmp);
		lst = lst->next;
	}
	return (newlst);
}
