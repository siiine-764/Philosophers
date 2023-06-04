/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:18:54 by mayache-          #+#    #+#             */
/*   Updated: 2023/06/04 22:23:22 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - '0';
	return (res * sign);
}

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	// i = 1;
	// while (av[i])
	// {
	// 	if (ft_atoi(av[i]) < 0)
	// 		return (1);
	// 	i++;
	// }
	return (0);
}