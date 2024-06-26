/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/26 19:15:35 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_threads(t_shared *shared);
static void	thread_func(t_thread *thread);
static int	check_philos(t_shared *shared);
static void	join_threads(t_shared *shared);

int	main(int argc, char **argv)
{
	t_shared	*shared;

	shared = (t_shared *)malloc(sizeof(t_shared));
	parsing_arg(shared, argc - 1, argv);
	set_threads(shared);
	check_philos(shared);
	join_threads(shared);
}

static void	set_threads(t_shared *shared)
{
	int			i;
	t_thread	thread;

	i = 0;
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
}

static void	thread_func(t_thread *thread)
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
		if (check_eat_cnt(thread) == 1)
			return (1);
			// 만약 다 먹었으면 그냥 스레드 종료시키면 된다 따로 메시지 출력할 필요 없음
		if (philo_sleeping(thread) == -1)
			return (-1);
		if (philo_thinking(thread) == -1)
			return (-1);
	}
}

static int	check_philos(t_shared *shared)
{
	int	i;
	struct timeval	current;
	struct timeval	last;
	int	gap;

	while (1)
	{
		i = 0;
		while (i < shared->number_of_philos)
		{
			last = shared->last_eat_time[i];
			gettimeofday(&current, 0);
			gap = (current.tv_sec - last.tv_sec) * 1000 + (current.tv_usec - last.tv_usec) / 1000;
			if (gap > shared->time_to_die)
			{
				pthread_mutex_lock(&shared->die_lock);
				shared->die_flag = 1;
				pthread_mutex_unlock(&shared->die_lock);
				return (0);
			}
			// die check
			pthread_mutex_lock(&shared->eat_finish_lock);
			if (shared->eat_finish_philos == shared->number_of_philos)
				return (0);
			pthread_mutex_unlock(&shared->eat_finish_lock);
			// eat finish 확인
			usleep(30);
		}
	}
	// TODO 계속 돌면서 철학자 상태 확인하기
	// TODO 철학자가 죽으면 쓰레드 회수하기, 모든 철학자가 밥을 다 먹었으면 쓰레드는 이미 회수 완료된 상태
	// 철학자들이 다 먹었는지도 확인해줘야 됨
	// 철학자들은 밥 다먹으면 알아서 스레드를 종료함
	// 철학자들 밥 다먹었는지 카운트 확인해서 다먹었으면 check philo 종료
	// 1000마이크로초 = 밀리초, 1000나노초 == 마이크로초 뮤텍스락 획득해제하는데 100나노초정도만 걸림
}

static void	join_threads(t_shared *shared)
{
	int	i;

	i = 0;
	while (i < shared->number_of_philos)
	{
		pthread_join(shared->philo[i], 0);
		i++;
	}
}
