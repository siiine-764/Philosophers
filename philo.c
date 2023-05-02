/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:30:43 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/02 05:29:22 by mayache-         ###   ########.fr       */
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
	}
	return (0);
}