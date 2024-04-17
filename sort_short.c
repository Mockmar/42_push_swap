#include "push_swap.h"

int	sort_short(t_list **lst)
{
	if (lst_sorted(*lst))
		return (1);
	if (lst_inverse(*lst) && t_ft_lstsize(*lst) == 2)
	{
		rotate_lst(&*lst);
		write(1, "ra\n", 3);
		return (1);
	}
	else if (lst_inverse(*lst))
	{
		rotate_lst(&*lst);
		swap(*lst);
		write(1, "ra\nsa\n", 6);
		return (1);
	}
	return (sort_short_2(&*lst));
}

int	sort_short_2(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->value > tmp->next->value
		&& tmp->next->value < tmp->next->next->value
		&& tmp->value > tmp->next->next->value)
	{
		rotate_lst(&*lst);
		write(1, "ra\n", 3);
		return (1);
	}
	if (tmp->value > tmp->next->value
		&& tmp->next->next->value > tmp->next->value)
	{
		swap(*lst);
		write(1, "sa\n", 3);
		return (1);
	}
	return (sort_short_3(&*lst));
}

int	sort_short_3(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->value < tmp->next->value && tmp->value < tmp->next->next->value)
	{
		reverse_lst(&*lst);
		swap(*lst);
		write(1, "rra\nsa\n", 7);
		return (1);
	}
	if (tmp->value < tmp->next->value && tmp->value > tmp->next->next->value)
	{
		reverse_lst(&*lst);
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	sort_hard(t_list **lst)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = *lst;
	lst_b = NULL;
	while (t_ft_lstsize(lst_a) > 3)
	{
		send_top(find_min(lst_a), &lst_a);
		push_top(&lst_a, &lst_b);
		write(1, "pb\n", 3);
	}
	sort_short(&lst_a);
	while (lst_b)
	{
		push_top(&lst_b, &lst_a);
		write(1, "pa\n", 3);
	}
	t_ft_lstclear(&lst_a);
	return (1);
}
