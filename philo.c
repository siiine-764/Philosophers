/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:36:26 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/12 16:04:04 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
	
int	main(int ac, char **av)
{
	t_info	*args;

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
		is_dead(args);
	int	i;
	i = 0;
	// while (i < args->nbr_of_philos)
	// {
	// 	if (pthread_join(args->philo[i].nbr_of_philos, NULL))
	// 		return 0;
	// 	i++;
	// }
	// while (i < args->nbr_of_philos)
	// {
	// 	pthread_mutex_destroy(&args->forks[i]);
	// 	pthread_mutex_destroy(&args->eating[i]);
	// 	pthread_mutex_destroy(&args->time[i]);
	// 	pthread_mutex_destroy(&args->dead_mut[i]);
	// 	i++;
	// }
	// pthread_mutex_destroy(&args->decalre);
		// pthread_mutex_lock(&args->decalre);
		// printf("%lld\n", current_time());
		// printf("%ld\n", args->start_tm);
		// if (!args->is_died && !args->all_eat)
		// 	printf("%lld\n", (current_time() - args->start_tm));
		// pthread_mutex_unlock(&args->decalre);
	}
	return (0);
}