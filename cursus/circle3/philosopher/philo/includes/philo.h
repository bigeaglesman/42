/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:03:06 by youngho           #+#    #+#             */
/*   Updated: 2024/06/19 23:24:56 by youngho          ###   ########.fr       */
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
	pthread_mutex_t	start_lock;
	pthread_mutex_t	*fork;
	pthread_t		*philo;
}t_arg;

int		ft_atoi(char *str);
void	parsing_arg(t_arg *arg, int num_arg, char **argv);

#endif