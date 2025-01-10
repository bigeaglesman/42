/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:45 by ycho2             #+#    #+#             */
/*   Updated: 2024/09/02 17:19:06 by ycho2            ###   ########.fr       */
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
	usleep(800 * shared->time_to_eat);
	while (get_current_time() - start < shared->time_to_eat)
		usleep(50);
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
	usleep(800 * shared->time_to_sleep);
	while (get_current_time() - start < shared->time_to_sleep)
		usleep(50);
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
