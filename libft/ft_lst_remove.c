/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:50:55 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/04 23:20:20 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_remove_front_if(t_list **head, void *data,
		void (*func)(void *))
{
	t_list	*curr;

	curr = *head;
	while (data == curr->content)
	{
		*head = curr->next;
		ft_lstdelone(curr, func);
		curr = *head;
	}
}

void	ft_lst_remove(t_list **head, void *content, void (*fct)(void *))
{
	t_list	*curr;
	t_list	*prev;

	if (!head || !*head || !fct)
		return ;
	ft_lst_remove_front_if(head, content, fct);
	if (!*head)
		return ;
	curr = (*head)->next;
	prev = *head;
	while (curr)
	{
		if (curr->content == content)
		{
			prev->next = curr->next;
			ft_lstdelone(curr, fct);
		}
		else
			prev = curr;
		curr = prev->next;
	}
}
