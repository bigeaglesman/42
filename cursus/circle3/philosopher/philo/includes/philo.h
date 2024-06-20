/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:03:06 by youngho           #+#    #+#             */
/*   Updated: 2024/06/20 19:22:28 by ycho2            ###   ########.fr       */
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

typedef struct s_arg
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat_times;
	int				*philo_stat;
	int				philo_nth;
	int				die_flag;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork;
	pthread_t		*philo;
	pthread_mutex_t	*stat_lock;
}t_arg;

int		ft_atoi(char *str);
void	parsing_arg(t_arg *arg, int num_arg, char **argv);
void	print_status(int action, t_arg *arg, struct timeval tv);

#endif