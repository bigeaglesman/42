/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:03:06 by youngho           #+#    #+#             */
/*   Updated: 2024/06/23 11:33:21 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define LEFT_FORK 0
# define RIGHT_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DEAD 5
# define FULL 6

typedef struct s_shared
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat_times;
	int				*philo_stat; //자신의 상태 저장해 놨다가 나중에 자원 회수해야됨
	int				die_flag;
	int				*last_eat_time;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork;
	pthread_t		*philo;
	pthread_mutex_t	*stat_lock;
	pthread_mutex_t	die_lock;
}t_shared;

typedef struct s_thread
{
	int			philo_nth;
	int			eat_cnt;
	t_shared	*shared;
}t_thread;

int		ft_atoi(char *str);
void	parsing_arg(t_shared *shared, int num_arg, char **argv);
int		print_status(int action, t_shared *shared, struct timeval tv);
void	update_status(int action, t_shared *shared);

#endif