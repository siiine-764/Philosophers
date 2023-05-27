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

int	main(int ac, char **ag)
{
	t_info	p;
	t_philo	*philo;

	if ((ac == 5 || ac == 6))
	{
		if (check_arg(ag) == 1)
			return (1);
		init_main(&p, ag);
		philo = malloc(sizeof(t_philo) * p.num);
		if (!philo)
			return (1);
		if (init_thread(&p, philo))
			return (1);
		ft_check_thread(&p, philo);
		ft_destroy_join(&p, philo);
	}
	return (0);
}
