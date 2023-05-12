/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:28:12 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/12 16:13:52 by mayache-         ###   ########.fr       */
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

void	my_usleep(int time)
{
	long init;

	init = current_time();
	while (current_time() < init + time)
		usleep(100);
}

void	print_routine(t_info *args, char *a, int id)
{
	// if (!args->is_died && !args->all_eat)
	pthread_mutex_lock(&args->decalre);
	printf("%lld %d %s\n", (current_time() - args->start_tm), id+1, a);
	pthread_mutex_unlock(&args->decalre);
}

int	sleep_hypnos(t_info *args,int				id)
{
	print_routine(args, "is sleeping", id);
	usleep(args->tm_to_slp);
	if (check_died(args) == 1)
	{
		return (1);
	}
	return (0);
}

int	think_descartes(t_info *args,int				id)
{
	print_routine(args, "is thinking", id);
	if (check_died(args) == 1)
		return(1);
	return(0);
}

int	eat_eta(t_info *args, int				id)
{
	if (check_died(args) == 1)
		return(1);
	pthread_mutex_lock(&args->forks[args->philo->id]);
	print_routine(args, "has take a fork", id);
	pthread_mutex_lock(&args->forks[(args->philo->id+1) % args->nbr_of_philos]);
	print_routine(args, "has take a fork", id);
	print_routine(args, "is eating", id);
	args->philo->last_meal = current_time();
	my_usleep(args->tm_to_eat);
	args->philo->meal_eated++;
	pthread_mutex_unlock(&args->forks[args->philo->id]);
	pthread_mutex_unlock(&args->forks[(args->philo->id+1) % args->nbr_of_philos]);
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

// int	is_died(t_info *args, int i)
// {
// 	int	ret;

// 	pthread_mutex_lock(&args->decalre);
// 	if (i)
// 		args->is_died = i;
// 	ret = args->is_died;
// 	pthread_mutex_unlock(&args->decalre);
// 	return (ret);
// }

void	is_dead(t_info *args)
{
	int		i;
	long	tm;

	i = -1;
	// printf("---->%ld\n", args->tm_to_die);
	// printf("--->%d\n", args->nbr_of_philos);
	while (++i < args->nbr_of_philos)
	{
		*args->dead = 0;
		pthread_mutex_lock(&args->time[i]);
		tm = (current_time() - args->philo[i].last_meal);
		pthread_mutex_unlock(&args->time[i]);
		if (tm >= args->tm_to_die)
		{
			print_routine(args, "died", i);
			// pthread_mutex_lock(&args->decalre);
			// if (*args->dead != 1)
			// 	pthread_mutex_unlock(&args->decalre);
			// is_died(args, i);
			// pthread_mutex_lock(&args->is_died);
			// if (i == 1)
			// {
			// 	// exit(1);
			// 	pthread_mutex_unlock(&args->is_died);
			// }
			// exit(1);
			// pthread_mutex_unlock(&args->is_died);
		}
	}
}