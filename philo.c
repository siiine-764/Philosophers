/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:36:26 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/24 20:00:05 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	check_death(t_philo *philo)
{
	long	tm;

	pthread_mutex_lock(philo->par->death);
	tm = current_time() - philo->meal;
	if (tm >= philo->par->t2d)
	{
		pthread_mutex_unlock(philo->par->death);
		print_part(philo, "died");
		philo->par->dead = 1;
		pthread_mutex_unlock(philo->lf);
		pthread_mutex_unlock(philo->rf);
		return (philo->par->dead);
	}
	pthread_mutex_unlock(philo->par->death);
	return (0);
}


int	check_meals(t_philo p, int last)
{
	if (last == p.par->num - 1
		&& p.iter_num == p.par->nbr_of_meals)
		my_usleep(300);
	return (0);
}

static void	check_thread(t_params *p, t_philo *philo)
{
	int	i;

	while (!philo->par->dead)
	{
		i = -1;
		while (++i < p->num)
			if (check_death(&philo[i]) || check_meals(philo[i], i))
			{
				philo->par->dead = 1;
				return ;
			}

	}
}

int	main(int ac, char **ag)
{
	t_params	p;

	if ((ac != 5 && ac != 6))
	{
		return (1);
	}
	// if ((ac == 5 && ac == 6))
	// {
		init_params(&p, ag);
		t_philo	*philo;

	philo = malloc(sizeof(t_philo) * p.num);
	if (!philo)
		return (0);
	if (init_thread(&p, philo))
		return (0);
	check_thread(&p, philo);
	ft_destroy_join(&p, philo);
		// return (EXIT_FAILURE);
	// }
	// return (EXIT_SUCCESS);
}


// int	main(int ac, char **av)
// {
// 	// int	i;
// 	t_info	*args;

// 	// i = 0;
// 	if (ac == 5 || ac == 6)
// 	{
// 		check_positive(av);
// 		args = malloc(sizeof(t_info));
// 		if (!args)
// 			return (0);
// 		if (!init_main(args, av))
// 		{
// 			free(args);
// 			return (0);
// 		}
// 		start_thread(args);
// 		// check_dead(args);
		
// 		// while (i < args->nbr_of_philos)
// 		// {
// 		// 	if (pthread_join(args->philo[i].nbr_of_philos, NULL))
// 		// 		return 0;
// 		// 	i++;
// 		// }
// 		// while (i < args->nbr_of_philos)
// 		// {
// 		// 	pthread_mutex_destroy(&args->forks[i]);
// 		// 	pthread_mutex_destroy(&args->eating[i]);
// 		// 	pthread_mutex_destroy(&args->time[i]);
// 		// 	i++;
// 		// }
// 		// pthread_mutex_destroy(&args->decalre);
// 	}
// 	return (0);
// }