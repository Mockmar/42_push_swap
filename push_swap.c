
#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	*lst_a;
	char	**tab;

	i = 1;
	if (ac == 2)
	{
		av[1] = remplace(av[1], "\t\v\r");
		tab = ft_split(av[1], ' ');
		i--;
	}
	else
		tab = av;
	if (!check_arg(ac, tab))
		return (message_error(ac, tab));
	lst_a = NULL;
	while (tab[i])
	{
		t_ft_lstadd_back(&lst_a, t_ft_lstnew(ft_atoi(tab[i])));
		i++;
	}
	if (ac == 2)
		free_tab(tab);
	solver(lst_a);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

int	message_error(int ac, char **tab)
{
	write(2, "Error\n", 6);
	if (ac == 2)
		free_tab(tab);
	return (1);
}

int	solver(t_list *lst_a)
{
	if (lst_sorted(lst_a))
		return (0);
	if (t_ft_lstsize(lst_a) <= 80)
		sort_hard(&lst_a);
	else if (t_ft_lstsize(lst_a) <= 300)
		sort_medium(&lst_a);
	else
		sort_medium_mediane(&lst_a);
	return (0);
}
