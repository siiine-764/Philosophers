/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:43:00 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/02 05:27:48 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	init_args(t_info *args, char **av)
{
	args->nbr_of_philos = ft_atoi(av[1]);
	args->tm_to_die = ft_atoi(av[2]);
	args->tm_to_eat = ft_atoi(av[3]);
	args->tm_to_slp = ft_atoi(av[4]);
	args->is_died = 0;
	args->all_eat = 0;
	args->start_tm = current_time();
	if (av[5] != 0)
		args->nbr_of_meals = ft_atoi(av[5]);
	else
		args->nbr_of_meals = -1;
}

int	alloc_args(t_info *args, char **av)
{
	args->philo = malloc(ft_atoi(av[1]) * sizeof(t_philo));
	if (!args->philo)
		return (0);
	args->forks = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
	if (!args->forks)
		return (0);
	args->time = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
	if (!args->time)
		return (0);
	args->eating = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
	if (!args->eating)
		return (0);
	return (1);
}

int	init_main(t_info *args, char **av)
{
	int	i;

	if (!alloc_args(args, av))
		return (0);
	init_args(args, av);
		if (pthread_mutex_init(&args->decalre, NULL))
		return (0);
	i = 0;
	while (i < args->nbr_of_philos)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (0);
		if (pthread_mutex_init(&args->time[i], NULL))
			return (0);
		if (pthread_mutex_init(&args->eating[i], NULL))
			return (0);
		i++;
	}
	return (1);
}