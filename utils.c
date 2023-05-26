/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:28:12 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/24 22:40:22 by mayache-         ###   ########.fr       */
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
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = (res * 10) + str[i++] - '0';
	}
	return (res * sign);
}

// void	check_positive(char **av)
// {
// 	int	i;

// 	i = 1;
// 	while (av[i])
// 	{
// 		if (ft_atoi(av[i]) <= 0)
// 			printf("Error\n");
// 		i++;
// 	}
// }

// long long	current_time(void)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
// }

// void	my_usleep(int time)
// {
// 	long init;

// 	init = current_time();
// 	while (current_time() < init + time)
// 		usleep(200);
// }

// void	print_routine(t_info *args, char *a, int id)
// {
// 	pthread_mutex_lock(&args->decalre);
// 	if (args->dead == 0 && args->all_eat == 0)
// 		printf("%lld %d %s\n", (current_time() - args->tm_to_start), id+1, a);
// 	pthread_mutex_unlock(&args->decalre);
// }

void	sleep_hypnos(t_philo *p)
{
	my_usleep(p->par->t2s);
	print_part(p, "is sleeping");
}

void	think_descartes(t_philo *p)
{
	print_part(p, "is thinking");
}
void	eat_eta(t_philo *p)
{
	pthread_mutex_lock(p->lf);
	print_part(p, "has taken a fork");
	pthread_mutex_lock(p->rf);
	print_part(p, "has taken a fork");
	pthread_mutex_lock(&p->par->eating[p->par->num]);
	p->meal = current_time();
	pthread_mutex_unlock(&p->par->eating[p->par->num]);
	my_usleep(p->par->t2e);
	print_part(p, "is eat");
	pthread_mutex_lock(&p->par->eating[p->par->num]);
		p->iter_num++;
	pthread_mutex_unlock(&p->par->eating[p->par->num]);
	pthread_mutex_unlock(p->lf);
	pthread_mutex_unlock(p->rf);
}

// int	eat_eta(t_info *args, int id)
// {
// 	pthread_mutex_lock(&args->forks[args->philo->fork_left]);
// 	print_routine(args, "has take a fork", id);
// 	if (args->nbr_of_philos == 1)
// 	{
// 		my_usleep(args->tm_to_die);
// 		// return ;	
// 	}
// 	pthread_mutex_lock(&args->forks[args->philo->fork_right]);
// 	print_routine(args, "has take a fork", id);
// 	print_routine(args, "is eating", id);

// 	pthread_mutex_lock(&args->time[args->philo->id - 1]);
// 	args->philo->last_meal = current_time();
// 	pthread_mutex_unlock(&args->time[args->philo->id - 1]);
	
// 		pthread_mutex_lock(&args->eating[args->philo->id -1]);
// 		args->philo->meal_eated++;
// 		pthread_mutex_unlock(&args->eating[args->philo->id -1]);
// 		my_usleep(args->tm_to_eat);
	
// 	pthread_mutex_unlock(&args->forks[args->philo->fork_left]);
// 	pthread_mutex_unlock(&args->forks[args->philo->fork_right]);

// 	// pthread_mutex_lock(&args->forks[args->philo->id]);
// 	// print_routine(args, "has take a fork", id);
// 	// pthread_mutex_lock(&args->forks[(args->philo->id + 1) % args->nbr_of_philos]);
// 	// print_routine(args, "has take a fork", id);
// 	// print_routine(args, "is eating", id);
// 	// args->philo->last_meal = current_time();
// 	// // my_usleep(args->tm_to_eat);
// 	// my_usleep(50);
// 	// args->philo->meal_eated++;
// 	// pthread_mutex_unlock(&args->forks[args->philo->id]);
// 	// pthread_mutex_unlock(&args->forks[(args->philo->id+1) % args->nbr_of_philos]);
// 	return (0);


// }

// int	is_died(t_info *info, int i)
// {
// 	pthread_mutex_lock(&info->decalre);
// 	if (i == 1)
// 		info->dead = i;
// 	pthread_mutex_unlock(&info->decalre);
// 	return (info->dead);
// }

// void	is_dead(t_info *args)
// {
// 	int i;
// 	long tm;

// 	i = 0;
// 	tm = 0;
// 	while (i < args->nbr_of_philos)
// 	{
// 		pthread_mutex_lock(&args->time[i]);
// 		tm = (current_time() - args->philo[i].last_meal);
// 		pthread_mutex_unlock(&args->time[i]);
// 		if (tm >= args->tm_to_die )
// 		{
// 			// printf("--->%d\n", (args->all_eat));
// 			// if (args->dead == 1)
// 			// {
// 				print_routine(args, "died", i);
// 				is_died(args, 1);
// 			// }
// 			// if (args->dead  != 0)
// 			// 	return ;
			
// 		}
// 		i++;
// 		// if (i > args[0].nbr_of_philos)
// 		// 	i = 0;
// 	}
// }

// void	check_all_eated(t_info *info)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < info->nbr_of_philos)
// 	{
// 		pthread_mutex_lock(&info->eating[i]);
// 		if (info->philo[i].meal_eated < info->nbr_of_meals)
// 		{
// 			pthread_mutex_unlock(&info->eating[i]);
// 			return ;
// 		}
// 		pthread_mutex_unlock(&info->eating[i]);
// 	}
// 	pthread_mutex_lock(&info->decalre);
// 	info->all_eat = 1;
// 	pthread_mutex_unlock(&info->decalre);
// }

// void		check_dead(t_info *args)
// {
// 	while (args->dead == 0)
// 	{
// 		is_dead(args);
// 		if (args->nbr_of_meals > 0)
// 		{
// 			check_all_eated(args);
// 		}
// 	}
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
		usleep(150);
}

void	print_part(t_philo *p, char *action)
{
	pthread_mutex_lock(p->par->death);
	if (p->par->dead)
	{
		pthread_mutex_unlock(p->par->death);
		return ;
	}
	pthread_mutex_lock(p->par->write);
	printf("%lld %d %s\n", current_time() - p->thread_start,
		p->id + 1, action);
	pthread_mutex_unlock(p->par->write);
	pthread_mutex_unlock(p->par->death);
}


void	ft_destroy_join(t_params *p, t_philo *philo)
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