#include "push_swap.h"

int	lst_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	lst_inverse(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->value <= lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_pos(t_list *lst, int nb)
{
	int	i;

	i = 1;
	while (lst && nb > lst->value)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
