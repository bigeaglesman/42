/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:01:42 by ycho2             #+#    #+#             */
/*   Updated: 2024/07/12 15:41:02 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// 필로소퍼 -> 데이터레이스가 안나게 밥을 잘 맥여라 -> 기아상태
// -> 데드락(교착상태) -> 상호배제된 거에 의해서 프로세스가 대기 상태로 죽는다. 
// -> 라이브락 -> 프로세스가 대기는 안하는데 다른 프로세스가 사용 자원을 놓지 않아서 그냥 무한히 확인만 하다 뒤지는거
// -> 이걸 해결할 떄 방법이 -> 효용, 무시, 예방(일부), 회피(대부분 사용)
// -> 스레드가 시작할 때 홀수번째 철학자는 100us 걍 대기를 시켜버려
// -> 포크를 잡는 순서를 다르게 한다.

// 포크 flag -> 1 | 0 -> 스핀락 -> 뮤텍스에 의해서 프로세스 대기하진 않는다.

static int	die_check(t_shared *shared);

int	print_status(int action, t_thread *thread) // -> 시간을 리턴값으로 뱉는다.
{
	char	*act_char[] = {"has taken a fork",
		"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};
	int	time;
	t_shared	*shared;

	shared = thread->shared;
	pthread_mutex_lock(&shared->print_lock); // -> 순서를 보장안해줘..
	if (die_check(shared))
	{
		pthread_mutex_unlock(&shared->print_lock);
		return (-1);
	}
	time = get_current_time() - thread->start;
	printf("%d %d %s\n", time, thread->philo_nth + 1, act_char[action]);
	pthread_mutex_unlock(&shared->print_lock);
	return (0);
}

static int	die_check(t_shared *shared)
{
	pthread_mutex_lock(&shared->die_lock);
	if (shared->die_flag == 1)
	{
		pthread_mutex_unlock(&shared->die_lock);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&shared->die_lock);
		return (0);
	}
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