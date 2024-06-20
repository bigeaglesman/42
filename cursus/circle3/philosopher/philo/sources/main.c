/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/20 22:31:52 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	parsing_arg(arg, argc - 1, argv);
	set_threads(arg);
}

void	set_threads(t_arg *arg)
{
	int i;

	i = 0;
	pthread_mutex_init(&arg->start_lock, 0);
	pthread_mutex_init(&arg->print_lock, 0);
	pthread_mutex_lock(&arg->start_lock);
	while (i < arg->number_of_philos)
	{
		arg->philo_nth = i;
		pthread_create(arg->philo[i], 0, (void *)&thread_func, &arg);
		i++;
	} 
	pthread_mutex_unlock(&arg->start_lock);
	check_philos(arg);
}

void	thread_func(t_arg *arg)
{
	philo_thinking(arg);
	pthread_mutex_lock(&arg->start_lock);
	pthread_mutex_unlock(&arg->start_lock);
	philo_thinking(arg);
	if (arg->philo_nth / 2)
		usleep(1000 * arg->time_to_eat);
	while (1)
	{
		philo_eating(arg);
		philo_sleeping(arg);
		philo_thinking(arg);
	}
}

void	check_philo(t_arg *arg)
{
	// TODO 계속 돌면서 철학자 상태 확인하기
	// TODO 철학자가 죽으면 쓰레드 회수하기, 모든 철학자가 밥을 다 먹었으면 쓰레드는 이미 회수 완료된 상태
}