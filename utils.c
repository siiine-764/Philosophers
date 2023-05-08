/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:28:12 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/08 20:31:54 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - '0';
	return (res * sign);
}

void	check_positive(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			printf("Error\n");
		i++;
	}
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_routine(t_info *args, char *a, int i)
{
	pthread_mutex_lock(&args->decalre);
	// if (!args->is_died && !args->all_eat)
	printf("%lld %d %s\n", (current_time() - args->start_tm), i, a);
	pthread_mutex_unlock(&args->decalre);
}

int	sleep_hypnos(t_info *args)
{
	print_routine(args, "is sleeping", args->philo->id);
	usleep(args->tm_to_slp * 1000);
	if (check_died(args) == 1)
		return (1);
	return (0);
}

int	think_descartes(t_info *args)
{
	print_routine(args, "is thinking", args->philo->id);
	if (check_died(args) == 1)
		return(1);
	return(0);
}

int	eat_eta(t_info *args)
{
	if (check_died(args) == 1)
		return(1);
	print_routine(args, "is eating", args->philo->id);
	pthread_mutex_lock(&args->time[args->philo->id - 1]);
	args->philo->last_meal = current_time();
	pthread_mutex_unlock(&args->time[args->philo->id - 1]);
	pthread_mutex_lock(&args->eating[args->philo->id - 1]);
	args->philo->meal_eated++;
	pthread_mutex_unlock(&args->eating[args->philo->id - 1]);
	pthread_mutex_lock(&args->forks[args->philo->id]);
	print_routine(args, "has take a fork", args->philo->id);
	// pthread_mutex_lock(&args->forks[(args->philo->id+1) % args->nbr_of_philos]);
	print_routine(args, "has take a fork", args->philo->id);
	// printf("yy\n");
	usleep(args->tm_to_eat);
	// printf("nnnn\n");
	pthread_mutex_unlock(&args->forks[args->philo->id]);
	// pthread_mutex_unlock(&args->forks[(args->philo->id+1) % args->nbr_of_philos]);
	// args->philo->time_of_eats++;
	return (0);
}

// int	died_thanatos(t_info *args)
// {
// 	int i = 0;
// 	// pthread_mutex_lock(&args->decalre);
// 	// i = args->is_died;
// 	// pthread_mutex_unlock(&args->decalre);
// 	return (i);
// }

int check_died(t_info *args)
{
	pthread_mutex_lock(&args->is_died);
	if ((args->tm_to_die) == 1)
	{
		pthread_mutex_unlock(&args->is_died);
		return (1);
	}
	pthread_mutex_unlock(&args->is_died);
	return (0);
}
