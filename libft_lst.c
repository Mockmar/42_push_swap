#include "push_swap.h"

int	t_ft_lstsize(t_list *lst)
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

t_list	*t_ft_lstnew(int value)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->value = value;
	element->next = NULL;
	return (element);
}

t_list	*t_ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	t_ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = t_ft_lstlast(*alst);
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}

void	t_ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
