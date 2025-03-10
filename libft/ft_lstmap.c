/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:04 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 20:58:59 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*copy_item(void *content, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new_elem;
	void	*data;

	if (!del || !f)
		return (NULL);
	data = (*f)(content);
	new_elem = ft_lstnew(data);
	if (!new_elem)
	{
		(*del)(data);
		return (NULL);
	}
	return (new_elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*p;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (0);
	head = copy_item(lst->content, f, del);
	if (!head)
		return (NULL);
	p = head;
	lst = lst->next;
	while (lst)
	{
		new_elem = copy_item(lst->content, f, del);
		if (!new_elem)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		p->next = new_elem;
		lst = lst->next;
		p = p->next;
	}
	return (head);
}
