/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:30:08 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/24 22:40:52 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*start_routine(void *i)
{
	t_philo	*p;

	p = (t_philo *)i;
	if (p->id % 2)
		my_usleep(p->info->t2e);
	while (!p->info->dead)
	{
		eat_eta(p);
		sleep_hypnos(p);
		think_descartes(p);
	}
	return (NULL);
}

int	init_thread(t_info *p, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < p->num)
		philo[i].l_f = &(p->fork[i]);
	i = -1;
	while (++i < p->num)
	{
		philo[i].id = i;
		philo[i].r_f = philo[(i + 1) % p->num].l_f;
		philo[i].thread_start =  current_time();
		philo[i].meal =  current_time();
		philo[i].iter_num = 0;
		philo[i].info = p;
		if (pthread_create(&philo[i].nbr_of_philos, NULL,
				&start_routine, &philo[i]) == -1)
			return (1);
	}
	return (0);
}
