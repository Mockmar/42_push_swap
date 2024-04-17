
#include "push_swap.h"

void	send_top(t_list *elem, t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = t_ft_lstsize(elem);
	tmp = *lst;
	if (t_ft_lstsize(elem) < t_ft_lstsize(*lst) / 2)
	{
		while (i)
		{
			reverse_lst(&*lst);
			write(1, "rra\n", 4);
			i--;
		}
	}
	else
	{
		while (i != t_ft_lstsize(*lst))
		{
			rotate_lst(&*lst);
			write(1, "ra\n", 3);
			i++;
		}
	}
}

void	print_mvt(t_mvt *mvt)
{
	while (mvt)
	{
		ft_putstr_fd(mvt->content, 1);
		mvt = mvt->next;
	}
}
