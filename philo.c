#include <stdio.h>
#include <unistd.h>

int	check_positive(char **a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if (ft_atoi(a[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_main	*args;

	if (ac == 5 || ac == 6)
	{
		if (!check_positive(av))
			return (0);
		args = malloc(sizeof(t_main));
		if (!args)
			return (0);
	}
	return (1);
}