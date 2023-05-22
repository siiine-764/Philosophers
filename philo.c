/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:36:26 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/22 16:12:33 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	int	i;
	t_info	*args;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		check_positive(av);
		args = malloc(sizeof(t_info));
		if (!args)
			return (0);
		if (!init_main(args, av))
		{
			free(args);
			return (0);
		}
		start_thread(args);
		while (args->dead == 1)
			is_dead(args);
		// while (!(args->dead) || !(args->all_eat))
		// {
			// while (i < args->nbr_of_philos)
			// {
			// 	pthread_mutex_lock(&args->time[i]);
			// 	long tm = (current_time() - args->philo[i].last_meal);
			// 	pthread_mutex_unlock(&args->time[i]);
			// 	if (tm >= args->tm_to_die)
			// 	{
			// 		pthread_mutex_lock(&args[i].decalre);
			// 		// if (!(args->dead))
			// 			printf("%lld %d died ggg\n", current_time() - args->tm_to_start, i);
			// 		pthread_mutex_unlock(&args[i].decalre);
			// 		pthread_mutex_lock(&args->decalre);
			// 		args->dead = 1;
			// 		pthread_mutex_unlock(&args->decalre);
			// 	}
			// 	i++;
			// 	// if (i > args[0].nbr_of_philos)
			// 	// 	i = 0;
			// }
		// }
		
		while (i < args->nbr_of_philos)
		{
			if (pthread_join(args->philo[i].nbr_of_philos, NULL))
				return 0;
			i++;
		}
		while (i < args->nbr_of_philos)
		{
			pthread_mutex_destroy(&args->forks[i]);
			pthread_mutex_destroy(&args->eating[i]);
			pthread_mutex_destroy(&args->time[i]);
			i++;
		}
		pthread_mutex_destroy(&args->decalre);
	}
	return (0);
}