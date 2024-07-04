/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:58:50 by youngho           #+#    #+#             */
/*   Updated: 2024/07/04 23:10:53 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_arg(t_shared *shared, int num_arg, char **argv);
static void	set_mutex(t_shared *shared);

int	parsing_arg(t_shared *shared, int num_arg, char **argv)
{
	if (num_arg == 4 || num_arg == 5)
		set_arg(shared, num_arg, argv);
	else
	{
		printf("arg num err\n");
		return (-1);
	}
	set_mutex(shared);
	return (0);
}

static void	set_arg(t_shared *shared, int num_arg, char **argv)
{
	shared->number_of_philos = ft_atoi(argv[1]);
	shared->time_to_die = ft_atoi(argv[2]);
	shared->time_to_eat = ft_atoi(argv[3]);
	shared->time_to_sleep = ft_atoi(argv[4]);
	if (num_arg == 5)
		shared->min_eat_times = ft_atoi(argv[5]);
	else
		shared->min_eat_times = -1;
	shared->die_flag = 0;
	shared->eat_finish_philos = 0;
}

static void	set_mutex(t_shared *shared)
{
	int i;

	i = 0;
	shared->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * shared->number_of_philos);
	while (i < shared->number_of_philos)
	{
		pthread_mutex_init(&shared->fork[i], 0);
		i++;
	}
	i = 0;
	shared->last_eat_time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * shared->number_of_philos);
	while (i < shared->number_of_philos)
	{
		pthread_mutex_init(&shared->last_eat_time[i], 0);
		i++;
	}
	shared->philo = (pthread_t *)malloc(sizeof(pthread_t) * shared->number_of_philos);
	pthread_mutex_init(&shared->start_lock, 0);
	pthread_mutex_init(&shared->print_lock, 0);
	pthread_mutex_init(&shared->die_lock, 0);
	pthread_mutex_init(&shared->eat_finish_lock, 0);
}
