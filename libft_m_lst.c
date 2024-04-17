
#include "push_swap.h"

void	ft_lstadd_back(t_mvt **alst, t_mvt *new)
{
	t_mvt	*tmp;

	tmp = ft_lstlast(*alst);
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}

void	ft_lstclear(t_mvt **lst)
{
	t_mvt	*tmp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_mvt	*ft_lstlast(t_mvt *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_mvt	*ft_lstnew(void *content)
{
	t_mvt	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

int	ft_lstsize(t_mvt *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
