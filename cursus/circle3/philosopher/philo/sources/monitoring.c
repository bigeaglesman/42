/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:32:32 by youngho           #+#    #+#             */
/*   Updated: 2024/07/13 01:08:18 by youngho          ###   ########.fr       */
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
					printf("%d %d died\n", time, i+1);
					pthread_mutex_unlock(&shared->print_lock);
					return (0);
				}
			}
			// die check
			pthread_mutex_lock(&shared->eat_finish_lock);
			if (shared->eat_finish_philos == shared->number_of_philos)
				return (1);
			pthread_mutex_unlock(&shared->eat_finish_lock);
			// eat finish 확인
			i++;
			usleep(50);
		}
	}
	// TODO 계속 돌면서 철학자 상태 확인하기
	// TODO 철학자가 죽으면 쓰레드 회수하기, 모든 철학자가 밥을 다 먹었으면 쓰레드는 이미 회수 완료된 상태
	// 철학자들이 다 먹었는지도 확인해줘야 됨
	// 철학자들은 밥 다먹으면 알아서 스레드를 종료함
	// 철학자들 밥 다먹었는지 카운트 확인해서 다먹었으면 check philo 종료
	// 1000마이크로초 = 밀리초, 1000나노초 == 마이크로초 뮤텍스락 획득해제하는데 100나노초정도만 걸림
}
