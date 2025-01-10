/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:32:32 by youngho           #+#    #+#             */
/*   Updated: 2024/09/02 17:12:24 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos(t_shared *shared, long long start)
{
	int			i;
	long long	last;
	int			gap;
	int			time;

	while (1)
	{
		i = 0;
		while (i < shared->number_of_philos)
		{
			pthread_mutex_lock(&shared->eat_time_lock[i]);
			last = shared->last_eat_time[i];
			pthread_mutex_unlock(&shared->eat_time_lock[i]);
			if (last != -1)
			{
				gap = get_current_time() - last;
				if (gap > shared->time_to_die)
				{
					pthread_mutex_lock(&shared->print_lock);
					pthread_mutex_lock(&shared->die_lock);
					shared->die_flag = 1;
					pthread_mutex_unlock(&shared->die_lock);
					time = get_current_time() - start;
					printf("%d %d died\n", time, i + 1);
					pthread_mutex_unlock(&shared->print_lock);
					return (0);
				}
			}
			pthread_mutex_lock(&shared->eat_finish_lock);
			if (shared->eat_finish_philos == shared->number_of_philos)
				return (1);
			pthread_mutex_unlock(&shared->eat_finish_lock);
			i++;
			usleep(50);
		}
	}
}
