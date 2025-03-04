#include "libft.h"
#include <stdio.h>

void	ft_lst_print(t_list *head)
{
	t_list	*lst;

	lst = head;
	while (lst)
	{
		printf("%s ->", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(int argc, char *argv[])
{
	t_list	*head;
	t_list	*lst[5];

	head = NULL;
	lst[0] = ft_lstnew(0);
	lst[1] = ft_lstnew(ft_strdup("A"));
	lst[2] = ft_lstnew(0);
	lst[3] = ft_lstnew(ft_strdup("C"));
	lst[4] = ft_lstnew(ft_strdup("D"));
	ft_lstadd_back(&head, lst[0]);
	ft_lstadd_back(&head, lst[1]);
	ft_lstadd_back(&head, lst[2]);
	ft_lstadd_back(&head, lst[3]);
	ft_lstadd_back(&head, lst[4]);
	ft_lst_print(head);
	ft_lst_remove(&head, 0, free);
	ft_lst_print(head);
	ft_lstclear(&head, free);
	return (EXIT_SUCCESS);
}
