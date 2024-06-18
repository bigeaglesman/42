/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/18 21:55:24 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	parsing_arg(&arg, argc - 1, argv);
	ready_thread(arg);
	
}


void	ready_thread(t_arg arg)
{
	t_mutex	mut;

	pthread_mutex_init(&(mut.start_lock), NULL);
	mut.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg.philo_num);
}