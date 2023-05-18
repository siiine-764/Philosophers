/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:30:08 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/18 16:52:11 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*start_routine(void *i)
{
	t_philo	*philo;
	t_info	*args;

	philo = (t_philo *)i;
	args = philo->info;
	if (philo->id % 2 == 0)
		my_usleep(1);
	while ((args->tm_to_die) != 1)
	{
		if (think_descartes(args, philo->id) == 1)
		{
			return (NULL);
		}
		if(eat_eta(args, philo->id) == 1)
		{
			return (NULL);
		}
		if (sleep_hypnos(args, philo->id) == 1)
		{
			return (NULL);
		}
	}
	return(NULL);
}

int	start_thread(t_info *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_of_philos)
	{
		args->philo[i].id = i;
		args->philo[i].fork_left = (i + 1) % args->nbr_of_philos;
		args->philo[i].fork_right = i;
		args->philo[i].meal_eated = 0;
		args->philo[i].info = args;
		args->philo[i].time_of_eats = 0;
		args->philo[i].last_meal = current_time();
		pthread_create(&args->philo[i].nbr_of_philos, NULL, &start_routine, &args->philo[i]);
		usleep(100);
		// if (pthread_create(&args->philo[i].nbr_of_philos, NULL, &start_routine,
		// 		&args->philo[i]))
		// 	return (0);
		// if (i == args->nbr_of_philos)
		// 	break ;
		i += 2;
	}
	i = 1;
	args->bl = 0;
	while (i < args->nbr_of_philos)
	{
		args->philo[i].id = i;
		args->philo[i].fork_left = (i + 1) % args->nbr_of_philos;
		args->philo[i].fork_right = i;
		args->philo[i].meal_eated = 0;
		args->philo[i].info = args;
		args->philo[i].time_of_eats = 0;
		args->philo[i].last_meal = current_time();
		pthread_create(&args->philo[i].nbr_of_philos, NULL, &start_routine, &args->philo[i]);
		usleep(100);
		// args->bl = 1;
		i += 2;
	}
	return (1);
}