/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:30:08 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/02 05:58:11 by mayache-         ###   ########.fr       */
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
		usleep(1500);
	// while (!is_died(args, 0) && !(args->all_eat))
	// {
	// 	picking(philo);
	// 	print_task(args, "is sleeping", philo->id);
	// 	better_usleep(args->tm_to_slp);
	// 	print_task(args, "is thinking", philo->id);
	// }
	return (NULL);
}

int	start_thread(t_info *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_of_philos)
	{
		args->philo[i].id = i + 1;
		args->philo[i].fork_left = i;
		args->philo[i].fork_right = (i + 1) % args->nbr_of_philos;
		args->philo[i].meal_eated = 0;
		args->philo[i].info = args;
		args->philo[i].last_meal = current_time();
		if (pthread_create(&args->philo[i].number_of_philo, NULL, &start_routine,
				&args->philo[i]))
			return (0);
		i++;
	}
	return (1);
}