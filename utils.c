/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:28:12 by mayache-          #+#    #+#             */
/*   Updated: 2023/06/04 22:28:02 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	sleep_hypnos(t_philo *p)
{
	print_part(p, "is sleeping");
	my_usleep(p->info->t2s);
}

void	think_descartes(t_philo *p)
{
	print_part(p, "is thinking");
}

void	eat_eta(t_philo *p)
{
	pthread_mutex_lock(p->l_f);
	print_part(p, "has taken a fork");
	pthread_mutex_lock(p->r_f);
	print_part(p, "has taken a fork");
	// pthread_mutex_lock(&p->info->eating[p->info->num]);
	p->meal = current_time();
	// pthread_mutex_unlock(&p->info->eating[p->info->num]);
	print_part(p, "is eating");
	my_usleep(p->info->t2e);
	// pthread_mutex_lock(&p->info->eating[p->info->num]);
	p->iter_num++;
	// pthread_mutex_unlock(&p->info->eating[p->info->num]);
	pthread_mutex_unlock(p->l_f);
	pthread_mutex_unlock(p->r_f);
}

// void	check_all_eated(t_info *info)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < info->nbr_of_philos)
// 	{
// 		pthread_mutex_lock(&info->eating[i]);
// 		if (info->philo[i].meal_eated < info->nbr_of_meals)
// 		{
// 			pthread_mutex_unlo ck(&info->eating[i]);
// 			return ;
// 		}
// 		pthread_mutex_unlock(&info->eating[i]);
// 	}
// 	pthread_mutex_lock(&info->decalre);
// 	info->all_eat = 1;
// 	pthread_mutex_unlock(&info->decalre);
// }


long long	current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	my_usleep(long time)
{
	long	init;

	init = current_time();
	while (current_time() < init + time)
		usleep(200);
}

void	print_part(t_philo *p, char *action)
{
	pthread_mutex_lock(p->info->death);
	if (p->info->dead)
	{
		pthread_mutex_unlock(p->info->death);
		return ;
	}
	pthread_mutex_lock(p->info->write);
	printf("%lld %d %s\n", current_time() - p->thread_start,
		p->id + 1, action);
	pthread_mutex_unlock(p->info->write);
	pthread_mutex_unlock(p->info->death);
}


void	ft_destroy_join(t_info *p, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < p->num)
		pthread_join(philo[i].nbr_of_philos, (void *)&philo[i]);
	pthread_mutex_destroy(p->death);
	pthread_mutex_destroy(p->eating);
	pthread_mutex_destroy(p->write);
	pthread_mutex_destroy(p->fork);
	// free(p->death);
	// free(p->fork);
	// free(philo);
}