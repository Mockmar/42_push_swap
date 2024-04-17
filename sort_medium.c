
#include "push_swap.h"

/*envoi dans b tout les elements de a qui sont en dessous de sa mediane
recommence l'operation jusqu'a cq a soit trier*/
int	sort_medium_mediane(t_list **lst)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		len;
	int		mediane;

	lst_a = *lst;
	lst_b = NULL;
	while (!lst_sorted(lst_a))
	{
		len = t_ft_lstsize(lst_a);
		mediane = find_mediane(lst_a);
		while (t_ft_lstsize(lst_a) > len / 2)
		{
			send_top(coutmin_putop(lst_a, mediane), &lst_a);
			push_top(&lst_a, &lst_b);
			write(1, "pb\n", 3);
		}
	}
	sort_smart(&lst_a, &lst_b);
	send_top(find_min(lst_a), &lst_a);
	t_ft_lstclear(&lst_a);
	return (1);
}

/*envoi dans b tout les elements de a jusqu'a cq a soit trier*/
int	sort_medium(t_list **lst)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = *lst;
	lst_b = NULL;
	while (!lst_sorted(lst_a))
	{
		push_top(&lst_a, &lst_b);
		write(1, "pb\n", 3);
	}
	sort_smart(&lst_a, &lst_b);
	send_top(find_min(lst_a), &lst_a);
	t_ft_lstclear(&lst_a);
	return (1);
}

/*execute les mouvement de la t_mvt*/
void	execute_mvt(t_list **lst_a, t_list **lst_b, t_mvt *mvt)
{
	while (mvt)
	{
		if (!ft_strcmp(mvt->content, "rra\n"))
			reverse_lst(&*lst_a);
		else if (!ft_strcmp(mvt->content, "rrb\n"))
			reverse_lst(&*lst_b);
		else if (!ft_strcmp(mvt->content, "ra\n"))
			rotate_lst(&*lst_a);
		else if (!ft_strcmp(mvt->content, "rb\n"))
			rotate_lst(&*lst_b);
		mvt = mvt->next;
	}
	push_top(&*lst_b, &*lst_a);
}

/*renvoi la liste des mvt dans a pour envoier elem au top de a*/
t_mvt	*mvt_totop_a(t_list *elem, t_list **lst)
{
	t_list	*tmp;
	t_mvt	*mvt;
	int		cpt;

	tmp = *lst;
	mvt = NULL;
	if (t_ft_lstsize(elem) < t_ft_lstsize(tmp) / 2)
	{
		cpt = t_ft_lstsize(elem);
		while (cpt)
		{
			ft_lstadd_back(&mvt, ft_lstnew("rra\n"));
			cpt--;
		}
	}
	else
	{
		cpt = t_ft_lstsize(tmp) - t_ft_lstsize(elem);
		while (cpt)
		{
			ft_lstadd_back(&mvt, ft_lstnew("ra\n"));
			cpt--;
		}
	}
	return (mvt);
}

/*renvoi la liste des mvt dans b pour envoier elem au top de b*/
t_mvt	*mvt_totop_b(t_list *elem, t_list **lst)
{
	t_list	*tmp;
	t_mvt	*mvt;
	int		cpt;

	tmp = *lst;
	mvt = NULL;
	if (t_ft_lstsize(elem) < t_ft_lstsize(tmp) / 2)
	{
		cpt = t_ft_lstsize(elem);
		while (cpt)
		{
			ft_lstadd_back(&mvt, ft_lstnew("rrb\n"));
			cpt--;
		}
	}
	else
	{
		cpt = t_ft_lstsize(tmp) - t_ft_lstsize(elem);
		while (cpt)
		{
			ft_lstadd_back(&mvt, ft_lstnew("rb\n"));
			cpt--;
		}
	}
	return (mvt);
}
