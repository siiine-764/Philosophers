/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:18:32 by mayache-          #+#    #+#             */
/*   Updated: 2023/06/04 22:18:36 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	check_died(t_philo *philo)
{
	long	tm;

	pthread_mutex_lock(philo->info->death);
	tm = current_time() - philo->meal;
	if (tm >= philo->info->t2d)
	{
		pthread_mutex_unlock(philo->info->death);
		print_part(philo, "died");
		philo->info->dead = 1;
		pthread_mutex_unlock(philo->l_f);
		pthread_mutex_unlock(philo->r_f);
		return (philo->info->dead);
	}
	pthread_mutex_unlock(philo->info->death);
	return (0);
}



int	check_eat(t_philo *philo, t_info *p)
{
	long	tm;

	pthread_mutex_lock(philo->info->death);
	tm = current_time() - philo->meal;
	if (tm >= p->nbr_of_meals)
	{
		pthread_mutex_unlock(philo->info->death);
		print_part(philo, "died");
		philo->info->dead = 1;
		pthread_mutex_unlock(philo->l_f);
		pthread_mutex_unlock(philo->r_f);
		return (philo->info->dead);
	}
	pthread_mutex_unlock(philo->info->death);
	return (0);
}
int	check_all_eated(t_philo p, int last)
{
	if (last == p.info->num
		&& p.iter_num == p.info->nbr_of_meals)
		my_usleep(300);
	// pthread_mutex_lock(&p.info->eating[last]);
	// p.check_meal = 1;
	// pthread_mutex_unlock(&p.info->eating[last]);
	return (0);
}

void	check_meals(t_info *p, t_philo *philo)
{
	int i;

	i = 0;
	(void)philo;
	while (i < p->num)
	{
		if((int)philo[i].iter_num < p->nbr_of_meals)
			return ;
		if (p->bl == 1)
		{
			// printf("--->%d\n", p->nbr_of_meals);
			p->nbr_of_meals--;
			philo->info->dead = 1;
		}
		i++;
	}
	// philo->info->dead = 1;
}

void	ft_check_thread(t_info *p, t_philo *philo)
{
	int	i;

	while (!philo->info->dead)
	{
		i = 0;
		while (i < p->num)
		{
			if (check_died(&philo[i]) || check_all_eated(philo[i], i))
			{
				philo->info->dead = 1;
				return ;
			}
			i++;
		}
		check_meals(p, philo);
	}
}