/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:01:42 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/26 19:20:18 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(int action, t_thread *thread)
{
	const char		**act_char = {"has taken a fork", "has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};
	long long		time;
	t_shared	*shared;
	struct timeval tv;

	gettimeofday(&tv, 0);
	shared = thread->shared;
	if (die_check())
		return (-1);
	time = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	pthread_mutex_lock(&shared->print_lock);
	printf("%lld %d %s\n", time, thread->philo_nth + 1, act_char[action]);
	pthread_mutex_unlock(&shared->print_lock);
	return (0);
}

// 먹는거
// 1. 왼쪽 포크를 잡는다. -> 그냥 해도 되ㅏㅁ.
// 2. 오른쪽 포크를 잡는다. -> 그냥 해도 됨.
// 3. 먹는다 -=> 200
// 3-1. 시간을 미리 기록하고 30
// 3-2. 먹어 -> 구조ㅓ체의 
// 3-3. 딜레이를준다. -> 200 - 지난 시간

// status - 0 left fork 1 right fork 2 eating 3 sleeping 4 thinking 
// 행동하기 전에 죽었는지 확인 print함수 실행전에 죽었는지 확인
// 밥 다먹었으면 쓰레드 종료
// 메인 스레드는 돌면서 죽은 스레드가 있는지 검사한다
// 이 과정에서 필로 스테이터스 배열과 다이 플래그의 뮤텍스 락을 획득 해야 한다
// 만약 철학자가 죽으면 다른 스레드들은 동작을 하지 않고 죽어야 하는가
// 다른 스레드에서 공통된 자원에 접근하는 경우 항사 뮤텍스 락을 획득해야지 race condition이 발생하지 않는다