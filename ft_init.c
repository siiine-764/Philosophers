/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:43:00 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/22 15:52:30 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// void	init_args(t_info *args, char **av)
// {
// 	args->nbr_of_philos = ft_atoi(av[1]);
// 	args->tm_to_die = ft_atoi(av[2]);
// 	args->tm_to_eat = ft_atoi(av[3]);
// 	args->tm_to_slp = ft_atoi(av[4]);
// 	args->dead = 0;
// 	args->all_eat = 0;
// 	args->tm_to_start = current_time();
// 	if (av[5] != 0)
// 		args->nbr_of_meals = ft_atoi(av[5]);
// 	else
// 		args->nbr_of_meals = -1;
// }

// int	alloc_args(t_info *args, char **av)
// {
// 	args->philo = malloc(ft_atoi(av[1]) * sizeof(t_philo));
// 	if (!args->philo)
// 		return (0);
// 	args->forks = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
// 	if (!args->forks)
// 		return (0);
// 	args->time = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
// 	if (!args->time)
// 		return (0);
// 	args->eating = malloc(sizeof(pthread_mutex_t));
// 	if (!args->eating)
// 		return (0);
// 	return (1);
// }


// int	init_main(t_params *params, char **av)
// {
// 	int	i;

// 	if (!alloc_args(args, av))
// 		return (0);
// 	init_args(args, av);
// 	if (pthread_mutex_init(&args->decalre, NULL))
// 		return (0);
// 	i = 0;
// 	while (i < args->nbr_of_philos)
// 	{
// 		pthread_mutex_init(&args->forks[i], NULL);
// 		pthread_mutex_init(&args->time[i], NULL);
// 		pthread_mutex_init(&args->eating[i], NULL);
// 		i++;
// 	}
// 	return (1);
// }



int	init_params(t_params *p, char **ag)
{
	int	mutex;

	mutex = -1;
	p->num = ft_atoi(ag[1]);
	p->t2d = ft_atoi(ag[2]);
	p->t2e = ft_atoi(ag[3]);
	p->t2s = ft_atoi(ag[4]);
	if (ag[5])
		p->nbr_of_meals = ft_atoi(ag[5]);
	else
		p->nbr_of_meals = -1;
	p->dead = 0;
	if (p->num > 0)
		mutex = init_params_mutex(p);
	return (mutex || p->num <= 0 || p->t2d <= 0 || p->t2e <= 0
		|| p->t2s <= 0 || p->nbr_of_meals == 0);
}

int	init_params_mutex(t_params *p)
{
	int	i;

	i = -1;
	p->death = malloc(sizeof(pthread_mutex_t));
	if (!p->death)
		return (1);
	p->eating = malloc(sizeof(pthread_mutex_t));
	if (!p->eating)
		return (1);
	p->write = malloc(sizeof(pthread_mutex_t));
	if (!p->write)
		return (1);
	p->fork = malloc(sizeof(pthread_mutex_t) * p->num);
	if (!p->fork)
		return (1);
	if (pthread_mutex_init(p->death, NULL) == -1)
		return (1);
	if (pthread_mutex_init(p->eating, NULL) == -1)
		return (1);
	if (pthread_mutex_init(p->write, NULL) == -1)
		return (1);
	while (++i < p->num)
		if (pthread_mutex_init(&p->fork[i], NULL) == -1)
			return (1);
	return (0);
}