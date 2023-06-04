/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:43:00 by mayache-          #+#    #+#             */
/*   Updated: 2023/06/04 20:13:36 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	init_main(t_info *p, char **ag)
{
	int	mutex;

	mutex = -1;
	p->num = ft_atoi(ag[1]);
	p->t2d = ft_atoi(ag[2]);
	p->t2e = ft_atoi(ag[3]);
	p->t2s = ft_atoi(ag[4]);
	p->check_meal = 0;
	if (ag[5])
	{
		p->nbr_of_meals = ft_atoi(ag[5]);
		p->bl = 1;
	}
	else
		p->nbr_of_meals = -1;
	p->dead = 0;
	if (p->num > 0)
		mutex = init_mutex(p);
	return (mutex || p->num <= 0 || p->t2d <= 0 || p->t2e <= 0
		|| p->t2s <= 0 || p->nbr_of_meals == 0);
}

int	init_mutex(t_info *p)
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