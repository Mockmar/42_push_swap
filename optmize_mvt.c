
#include "push_swap.h"

t_mvt	*optimize_rr(t_mvt *mvt)
{
	t_mvt	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (mvt && !ft_strcmp(mvt->content, "ra\n"))
	{
		while (mvt && !ft_strcmp(mvt->content, "ra\n"))
		{
			i++;
			mvt = mvt->next;
		}
		if (mvt && !ft_strcmp(mvt->content, "rb\n"))
		{
			tmp = optimize_rr_2(mvt, i);
		}
	}
	return (tmp);
}

t_mvt	*optimize_rr_2(t_mvt *mvt, int i)
{
	t_mvt	*tmp;

	tmp = NULL;
	while (mvt && !ft_strcmp(mvt->content, "rb\n") && i)
	{
		ft_lstadd_back(&tmp, ft_lstnew("rr\n"));
		i--;
		mvt = mvt->next;
	}
	while (i)
	{
		ft_lstadd_back(&tmp, ft_lstnew("ra\n"));
		i--;
	}
	while (mvt)
	{
		ft_lstadd_back(&tmp, ft_lstnew("rb\n"));
		mvt = mvt->next;
	}
	return (tmp);
}

t_mvt	*optimize_rrr(t_mvt *mvt)
{
	t_mvt	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (mvt && !ft_strcmp(mvt->content, "rra\n"))
	{
		while (mvt && !ft_strcmp(mvt->content, "rra\n"))
		{
			i++;
			mvt = mvt->next;
		}
		if (mvt && !ft_strcmp(mvt->content, "rrb\n"))
		{
			tmp = optimize_rrr_2(mvt, i);
		}
	}
	return (tmp);
}

t_mvt	*optimize_rrr_2(t_mvt *mvt, int i)
{
	t_mvt	*tmp;

	tmp = NULL;
	while (mvt && !ft_strcmp(mvt->content, "rrb\n") && i)
	{
		ft_lstadd_back(&tmp, ft_lstnew("rrr\n"));
		i--;
		mvt = mvt->next;
	}
	while (i)
	{
		ft_lstadd_back(&tmp, ft_lstnew("rra\n"));
		i--;
	}
	while (mvt)
	{
		ft_lstadd_back(&tmp, ft_lstnew("rrb\n"));
		mvt = mvt->next;
	}
	return (tmp);
}

t_mvt	*optimize(t_mvt *mvt)
{
	t_mvt	*tmp;

	tmp = optimize_rr(mvt);
	if (tmp)
	{
		ft_lstclear(&mvt);
		ft_lstadd_back(&tmp, ft_lstnew("pa\n"));
		return (tmp);
	}
	tmp = optimize_rrr(mvt);
	if (tmp)
	{
		ft_lstclear(&mvt);
		ft_lstadd_back(&tmp, ft_lstnew("pa\n"));
		return (tmp);
	}
	ft_lstadd_back(&mvt, ft_lstnew("pa\n"));
	return (mvt);
}
