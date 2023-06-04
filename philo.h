/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:59:30 by mayache-          #+#    #+#             */
/*   Updated: 2023/06/04 20:13:22 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>


typedef struct s_infos
{
	int				num;
	int				t2d;
	int				t2e;
	int				t2s;
	int				nbr_of_meals;
	int				check_meal;
	int				dead;
	int				bl;
	pthread_mutex_t	*death;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*write;
	pthread_mutex_t	*fork;
}	t_info;
typedef struct s_philo
{
	int				id;
	int				iter_num;
	long			thread_start;
	long			meal;
	pthread_t		nbr_of_philos;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	t_info		*info;
}	t_philo;

///// chech input /////
int		ft_atoi(const char *str);
int		check_arg(char **av);

///// functions utils /////
long long	current_time(void);
void		my_usleep(long time);
void		print_part(t_philo *p, char *action);
void	think_descartes(t_philo *p);
void	sleep_hypnos(t_philo *p);
void	eat_eta(t_philo *p);

///// functions init /////
int		init_main(t_info *p, char **ag);
int		init_mutex(t_info *p);
int		init_thread(t_info *p, t_philo *philo);
void	*start_routine(void *i);

///// chech threads /////
void		ft_check_thread(t_info *p, t_philo *philo);
int			check_all_eated(t_philo p, int last);
int			check_died(t_philo *philo);

///// function destroy and free /////
void	ft_destroy_join(t_info *p, t_philo *philo);
#endif