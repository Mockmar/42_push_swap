
#include "push_swap.h"

int	str_is_not_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	check_doublons(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!ft_strcmp(tab[i], tab[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	if (ac <= 1)
		return (0);
	if (!check_doublons(av))
		return (0);
	while (av[i])
	{
		if (!str_is_not_nbr(av[i]) || !hors_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	hors_int(char *str)
{
	int	nb;
	int	i;

	nb = ft_atoi(str);
	if (!ft_strcmp("-2147483648", str))
		return (1);
	i = ft_strlen(str) - 1;
	if ((nb < 0 && str[0] != '-' ) || (nb >= 0 && str[0] == '-'))
		return (0);
	if (nb == 0 && str[0] == '0')
		return (1);
	else if (nb == 0 && str[0] != '0')
		return (0);
	if (nb < 0)
		nb = -nb;
	while (i >= 0)
	{
		if (i == 0 && str[i] == '-')
			return (1);
		if (str[i] - 48 != nb % 10)
			return (0);
		nb = nb / 10;
		i--;
	}
	return (1);
}

char	*remplace(char *str, char *liste)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (liste[j])
		{
			if (str[i] == liste[j])
			{
				str[i] = ' ';
			}
			j++;
		}
		i++;
	}
	return (str);
}
