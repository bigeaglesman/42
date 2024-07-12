/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:45 by ycho2             #+#    #+#             */
/*   Updated: 2024/07/13 02:14:40 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_thinking(t_thread *thread)
{
	thread->status = THINKING;
	if (print_status(THINKING, thread))
		return (-1);
	return (0);
}

int	philo_eating(t_thread *thread)
{
	long long	start;
	t_shared	*shared;

	shared = thread->shared;
	if (grab_fork(thread, thread->philo_nth, thread->right_fork) == -1)
		return (-1);
	thread->status = EATING;
	start = get_current_time();
	pthread_mutex_lock(&shared->eat_time_lock[thread->philo_nth]);
	shared->last_eat_time[thread->philo_nth] = get_current_time();
	pthread_mutex_unlock(&shared->eat_time_lock[thread->philo_nth]);
	if (print_status(EATING, thread) == -1)
		return (-1);
	usleep(800*shared->time_to_eat);
	while (get_current_time() - start < shared->time_to_eat)
		usleep(50);
	// rest = shared->time_to_eat * 1000 - (1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_usec - start.tv_usec) / 1000);
	// usleep(rest); // -> ㅇㅠ스ㄹ립을 크게 걸면 무조건 오차가 발생해서 1ms
	// 여기 고쳐야됨 usleep은 시간이 보장이 안되서 최대한 잘게 넣는게 좋음 차라리 80프로까지는 크게주고 나머지를 잘게주는형식으로 하는게 좋을것
	thread->eat_cnt++;
	pthread_mutex_unlock(&shared->fork[thread->philo_nth]);
	pthread_mutex_unlock(&shared->fork[thread->right_fork]);
	return (0);
}

int	philo_sleeping(t_thread *thread)
{
	t_shared	*shared;
	long long	start;

	shared = thread->shared;
	start = get_current_time();
	thread->status = SLEEPING;
	if (print_status(SLEEPING, thread) == -1)
		return (-1);
	usleep(800*shared->time_to_sleep);
	while (get_current_time() - start < shared->time_to_sleep)
		usleep(50);
	// 여기도 위의 usleep과 똑같음 while문 돌려야됨
	return (0);
}

int	grab_fork(t_thread *thread, int left_fork, int right_fork)
{
	t_shared	*shared;

	shared = thread ->shared;
	pthread_mutex_lock(&shared->fork[left_fork]);
	thread->status = LEFT_FORK;
	if (print_status(LEFT_FORK, thread) == -1)
		return (-1);
	if (shared->number_of_philos == 1)
		return (-1);
	pthread_mutex_lock(&shared->fork[right_fork]);
	thread->status = RIGHT_FORK;
	if (print_status(RIGHT_FORK, thread) == -1)
		return (-1);
	return (0);
}


int	check_eat_cnt(t_thread *thread)
{
	t_shared	*shared;

	shared = thread->shared;
	if (thread->eat_cnt == shared->min_eat_times)
	{
		pthread_mutex_lock(&shared->eat_time_lock[thread->philo_nth]);
		shared->last_eat_time[thread->philo_nth] = -1;
		pthread_mutex_unlock(&shared->eat_time_lock[thread->philo_nth]);
		pthread_mutex_lock(&shared->eat_finish_lock);
		shared->eat_finish_philos++;
		pthread_mutex_unlock(&shared->eat_finish_lock);
		return (1);
	}
	return (0);
}
