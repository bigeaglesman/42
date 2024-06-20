/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:01:42 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/20 22:31:51 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int action, t_arg *arg, struct timeval tv)
{
	const char		**act_char = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};
	long long		time;

	time = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	pthread_mutex_lock(&arg->print_lock);
	printf("%lld %d %s\n", time, arg->philo_nth, act_char[action]);
	pthread_mutex_unlock(&arg->print_lock);
}

// 먹는거
// 1. 왼쪽 포크를 잡는다. -> 그냥 해도 되ㅏㅁ.
// 2. 오른쪽 포크를 잡는다. -> 그냥 해도 됨.
// 3. 먹는다 -=> 200
// 3-1. 시간을 미리 기록하고 30
// 3-2. 먹어 -> 구조ㅓ체의 
// 3-3. 딜레이를준다. -> 200 - 지난 시간
