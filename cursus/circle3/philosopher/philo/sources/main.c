/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/19 23:38:06 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	parsing_arg(&arg, argc - 1, argv);
	set_threads(arg);
	
}


void	set_threads(t_arg arg)
{
	int i;

	i = 0;
	pthread_mutex_init(&(arg.start_lock), 0);
	pthread_mutex_lock(&arg.start_lock);
	while (i < arg.philo_num)
	{
		pthread_create(arg.philo[i], 0, void *(*start_fun)(void *), 0);
		i++;
	}
}