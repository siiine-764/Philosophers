/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:59:30 by mayache-          #+#    #+#             */
/*   Updated: 2023/05/24 22:40:33 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	int				meal_eated;
	int				time_of_eats;
	long long		last_meal;
	pthread_t		nbr_of_philos;
	struct s_info	*info;
} t_philo;

typedef struct s_info
{
    int             nbr_of_philos;
    int             nbr_of_meals;
    int             tm_to_slp;
    int             tm_to_eat;
    int				tm_to_die;
    long            tm_to_start;
    int             all_eat;
	int 			dead;
    t_philo			*philo;
	int				bl;
	
    pthread_mutex_t	is_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	decalre;
	pthread_mutex_t	*time;
	pthread_mutex_t	*eating;
} t_info;

void		my_usleep(int time);


/*####### functions to check arguments #######*/
void		check_positive(char **av);

/*####### functions to init #######*/
void		init_args(t_info *args, char **av);
int			alloc_args(t_info *args, char **av);
int			init_main(t_info *args, char **av);
void		is_dead(t_info *args);
void		check_dead(t_info *args);
/*########## functions to start   #########*/
void	*start_routine(void *i);
int		start_thread(t_info *args);
int		sleep_hypnos(t_info *args, int				id);
int		eat_eta(t_info *args,int				id);
int		is_died(t_info *args, int i);
void	check_all_eated(t_info *info);
// int		died_thanatos(t_info *args);
int		think_descartes(t_info *args,int				id);
// int		check_died(t_info *args);
/*####### functions to utils #######*/
int			ft_atoi(const char *str);
long long	current_time(void);
void		print_routine(t_info *args, char *a, int i);
#endif