/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:30:43 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/02 07:47:13 by codespace        ###   ########.fr       */
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
		pthread_mutex_lock(&args->decalre);
		printf("%lld\n", current_time());
		printf("%ld\n", args->start_tm);
		if (!args->is_died && !args->all_eat)
			printf("%lld\n", (current_time() - args->start_tm));
		pthread_mutex_unlock(&args->decalre);
	}
	return (0);
}