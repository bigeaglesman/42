/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:03:06 by youngho           #+#    #+#             */
/*   Updated: 2024/06/18 20:35:42 by ycho2            ###   ########.fr       */
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
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat_times;
}t_arg;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	start_lock;
}t_mutex;

int		ft_atoi(char *str);
void	parsing_arg(t_arg *arg, int num_arg, char **argv);
#endif