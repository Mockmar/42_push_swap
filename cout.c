
#include "push_swap.h"
/*renvois l'element en dessous de la mediane le plus facile a mettre au top*/
t_list	*coutmin_putop(t_list *lst, int mediane)
{
	t_list	*elem;
	t_list	*head;
	int		min;

	head = lst;
	min = t_ft_lstsize(head) + 1;
	while (lst)
	{
		if (lst->value <= mediane
			&& (t_ft_lstsize(lst) < min
				|| t_ft_lstsize(head) - t_ft_lstsize(lst) < min))
		{
			elem = lst;
			min = t_ft_lstsize(elem);
			if (min > t_ft_lstsize(head) - t_ft_lstsize(elem))
				min = t_ft_lstsize(head) - t_ft_lstsize(elem);
		}
		lst = lst->next;
	}
	return (elem);
}

/*trouve le bon element a mettre au top de a pour acueillir l'elem*/
t_list	*find_pos_a(t_list *elem, t_list *lst)
{
	t_mvt	*mvt;

	mvt = NULL;
	if (elem->value > find_max(lst)->value)
		return (find_min(lst));
	else if (elem->value < find_min(lst)->value)
		return (find_min(lst));
	else
	{
		while (lst && lst->next)
		{
			if (elem->value > lst->value && elem->value < lst->next->value)
				return (lst->next);
			lst = lst->next;
		}
	}
	return (NULL);
}

/*trouve le bonne element a push et renvoi la liste des mvt a faire*/
t_mvt	*mvt_min(t_list *lst_a, t_list *lst_b, int min_mvt)
{
	t_list	*head_b;
	t_mvt	*save_mvt;
	t_mvt	*mvt_a;
	t_mvt	*mvt_b;

	head_b = lst_b;
	save_mvt = NULL;
	while (lst_b)
	{
		mvt_a = mvt_totop_a(find_pos_a(lst_b, lst_a), &lst_a);
		mvt_b = mvt_totop_b(lst_b, &head_b);
		ft_lstadd_back(&mvt_a, mvt_b);
		if (ft_lstsize(mvt_a) < min_mvt)
		{
			if (save_mvt)
				ft_lstclear(&save_mvt);
			save_mvt = mvt_a;
			min_mvt = ft_lstsize(save_mvt);
		}
		else
			ft_lstclear(&mvt_a);
		lst_b = lst_b->next;
	}
	return (save_mvt);
}

/*trouve la liste des bon mouv et l execute*/
void	sort_smart(t_list **lst_a, t_list **lst_b)
{
	t_mvt	*mvt;
	t_list	*l_b;

	l_b = *lst_b;
	while (l_b)
	{
		mvt = mvt_min(*lst_a, l_b, t_ft_lstsize(*lst_a));
		execute_mvt(&*lst_a, &l_b, mvt);
		mvt = optimize(mvt);
		print_mvt(mvt);
		ft_lstclear(&mvt);
	}
}
