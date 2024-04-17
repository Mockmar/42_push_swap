
#include "push_swap.h"

t_list	*find_min(t_list *lst)
{
	t_list	*tmp;
	int		min;

	min = lst->value;
	tmp = lst;
	while (lst)
	{
		if (lst->value < min)
		{
			min = lst->value;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

t_list	*find_max(t_list *lst)
{
	t_list	*tmp;
	int		max;

	max = lst->value;
	tmp = lst;
	while (lst)
	{
		if (lst->value > max)
		{
			max = lst->value;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	find_mediane(t_list *lst)
{
	t_list	*tmp;
	t_list	*head;
	int		mediane;
	int		cpt;
	int		len;

	len = t_ft_lstsize(lst);
	head = lst;
	while (lst)
	{
		tmp = head;
		mediane = lst->value;
		cpt = 0;
		while (tmp)
		{
			if (mediane > tmp->value)
				cpt++;
			tmp = tmp->next;
		}
		if (cpt == len / 2 || cpt == (len + 1) / 2)
			return (mediane);
		lst = lst->next;
	}
	return (0);
}
