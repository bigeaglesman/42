/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:11:53 by youngho           #+#    #+#             */
/*   Updated: 2024/07/13 15:02:47 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	return_fork(t_thread *thread);

int	thread_func(t_thread *thread)
{
	t_shared	*shared;

	shared = thread->shared;
	pthread_mutex_lock(&shared->start_lock);
	pthread_mutex_unlock(&shared->start_lock);
	if (thread->philo_nth % 2 == 1)
		usleep(1000 * shared->time_to_eat);
	philo_thinking(thread);
	while (1)
	{
		if (philo_eating(thread) == -1)
		{
			return_fork(thread);
			return (-1);
		}
		if (check_eat_cnt(thread) == 1)
			return (1);
		if (philo_sleeping(thread) == -1)
			return (-1);
		if (philo_thinking(thread) == -1)
			return (-1);
	}
}

static void	return_fork(t_thread *thread)
{
	t_shared	*shared;

	shared = thread->shared;
	if (thread->status == 0)
		pthread_mutex_unlock(&shared->fork[thread->philo_nth]);
	if (thread->status == 1)
		pthread_mutex_unlock(&shared->fork[thread->right_fork]);
}
