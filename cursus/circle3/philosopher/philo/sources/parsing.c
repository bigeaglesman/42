/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:58:50 by youngho           #+#    #+#             */
/*   Updated: 2024/06/20 17:10:39 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_arg(t_arg *arg, int num_arg, char **argv)
{
	int i;

	i = 0;
	if (num_arg == 4 || num_arg == 5)
	{
		arg->number_of_philos = ft_atoi(argv[1]);
		arg->time_to_die = ft_atoi(argv[2]);
		arg->time_to_eat = ft_atoi(argv[3]);
		arg->time_to_sleep = ft_atoi(argv[4]);
		if (num_arg == 5)
			arg->min_eat_times = ft_atoi(argv[5]);
		else
			arg->min_eat_times = -1;
	}
	else
		printf("arg num err\n");
	arg->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg->number_of_philos);
	while (i < arg->number_of_philos)
	{
		pthread_mutex_init(&arg->fork[i], 0);
		i++;
	}
	arg->philo = (pthread_t *)malloc(sizeof(pthread_t) * arg->number_of_philos);
}
