
#include "push_swap.h"

void	push_top(t_list **lst_send, t_list **lst_receive)
{
	t_list	*temp;
	t_list	*temp2;

	if (t_ft_lstsize(*lst_send) > 0)
	{
		temp = *lst_send;
		temp2 = (*lst_send)->next;
		temp->next = *lst_receive;
		*lst_send = temp2;
		*lst_receive = temp;
	}
}

void	reverse_lst(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (t_ft_lstsize(*lst) > 1)
	{
		temp2 = *lst;
		while (temp2->next->next)
			temp2 = temp2->next;
		temp = temp2->next;
		temp2->next = NULL;
		temp->next = *lst;
		*lst = temp;
	}
}

void	rotate_lst(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (t_ft_lstsize(*lst) > 1)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp2 = t_ft_lstlast(*lst);
		temp2->next = temp;
		temp->next = NULL;
	}
}

void	swap(t_list *lst)
{
	int	first_value;

	if (t_ft_lstsize(lst) > 1)
	{
		first_value = lst->value;
		lst->value = lst->next->value;
		lst->next->value = first_value;
	}
}
