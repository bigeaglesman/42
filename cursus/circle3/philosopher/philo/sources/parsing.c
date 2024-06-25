/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:58:50 by youngho           #+#    #+#             */
/*   Updated: 2024/06/25 18:20:50 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing_arg(t_shared *shared, int num_arg, char **argv)
{
	int i;

	i = 0;
	if (num_arg == 4 || num_arg == 5)
		set_arg(shared, num_arg, argv);
	else
	{
		printf("arg num err\n");
		return (-1);
	}
	shared->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * shared->number_of_philos);
	while (i < shared->number_of_philos)
	{
		pthread_mutex_init(&shared->fork[i], 0);
		i++;
	}
	shared->philo = (pthread_t *)malloc(sizeof(pthread_t) * shared->number_of_philos);
}

void	set_arg(t_shared *shared, int num_arg, char **argv)
{
	shared->number_of_philos = ft_atoi(argv[1]);
	shared->time_to_die = ft_atoi(argv[2]);
	shared->time_to_eat = ft_atoi(argv[3]);
	shared->time_to_sleep = ft_atoi(argv[4]);
	if (num_arg == 5)
		shared->min_eat_times = ft_atoi(argv[5]);
	else
		shared->min_eat_times = -1;
}