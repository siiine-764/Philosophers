/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:28:12 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/04 09:29:52 by mayache-         ###   ########.fr       */
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

void	sleep_hypnos(t_info *args)
{
	// long long	i;

	// i = current_time();
	// while (1)
	// {
	// 	if (current_time() - i >= slp)
	// 		break ;
	print_routine(args, "is sleeping", args->philo->id);
	usleep(args->tm_to_slp * 1000);
	// }
}

void	think_descartes(t_info *args)
{
	print_routine(args, "is thinking", args->philo->id);	
}

void	eat_eta(t_info *args)
{
	pthread_mutex_lock(&args->forks[args->philo->fork_left]);
	print_routine(args, "has take a fork", args->philo->id);
	pthread_mutex_lock(&args->forks[args->philo->fork_right]);
	print_routine(args, "has taken a fork", args->philo->id);
	print_routine(args, "is eating", args->philo->id);
	usleep(args->tm_to_eat * 1000);
	pthread_mutex_unlock(&args->forks[args->philo->fork_left]);
	pthread_mutex_unlock(&args->forks[args->philo->fork_right]);
	args->philo->time_of_eats++;
}

int	died_thanatos(t_info *args)
{
	int i = 0;
	pthread_mutex_lock(&args->decalre);
	i = args->is_died;
	pthread_mutex_unlock(&args->decalre);
	return (i);
}