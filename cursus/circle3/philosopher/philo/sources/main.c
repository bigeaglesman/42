/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/25 18:12:21 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_shared	*shared;

	shared = (t_shared *)malloc(sizeof(t_shared));
	parsing_arg(shared, argc - 1, argv);
	set_threads(shared);
}

void	set_threads(t_shared *shared)
{
	int			i;
	t_thread	thread;

	i = 0;
	pthread_mutex_init(&shared->start_lock, 0);
	pthread_mutex_init(&shared->print_lock, 0);
	pthread_mutex_lock(&shared->start_lock);
	while (i < shared->number_of_philos)
	{
		thread.eat_cnt = 0;
		thread.philo_nth = i;
		thread.shared = shared;
		pthread_create(shared->philo[i], 0, (void *)&thread_func, &thread);
		i++;
	} 
	pthread_mutex_unlock(&shared->start_lock);
	check_philos(shared);
}

void	thread_func(t_thread *thread)
{
	t_shared *shared;

	shared = thread->shared;
	philo_thinking(shared);
	pthread_mutex_lock(&shared->start_lock);
	pthread_mutex_unlock(&shared->start_lock);
	philo_thinking(shared);
	if (thread->philo_nth / 2)
		usleep(1000 * shared->time_to_eat);
	while (1)
	{
		if (philo_eating(thread) == -1)
			return (-1);
		check_eat_cnt(thread);
			return (0);
			// 만약 다 먹었으면 그냥 스레드 종료시키면 된다 따로 메시지 출력할 필요 없음
		if (philo_sleeping(shared) == -1)
			return (-1);
		if (philo_thinking(shared) == -1)
			return (-1);
	}
}

void	check_philos(t_shared *shared)
{

	// TODO 계속 돌면서 철학자 상태 확인하기
	// TODO 철학자가 죽으면 쓰레드 회수하기, 모든 철학자가 밥을 다 먹었으면 쓰레드는 이미 회수 완료된 상태
}

int	check_eat_cnt(t_thread *thread)
{
	t_shared	*shared;

	shared = thread->shared;
	if (shared->min_eat_times != -1 && thread->eat_cnt == shared->min_eat_times -1)
		return (1);
	else
		return (0);
}