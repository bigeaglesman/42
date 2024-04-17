/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:07:55 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/17 12:05:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_an(t_mte *mte, int min, int max);
static void sort_bn(t_mte *mte, int min, int max);
static void sort_bn_sub(t_mte *mte, int min, int max, int n);

void sort_a(t_mte *mte, int min, int max)
{
	const int n = max - min + 1; //pivot 정해주기
	const int pivot_1 = n/3 + n%3;
	const int pivot_2 = n/3 * 2 + n%3;
	int i;

	if (n == 2) //n이 1인 경우는 건드리지 않는다 n이 2인 경우는 a스택 위 2대의 값을 비교해서 정렬한다
	{
		if (mte->arr[mte->divide-1].label > mte->arr[mte->divide-2].label)
			swap(0, mte);
	}
	else if (n == 3)
		optimize3_a(mte);
	else if (n > 3)
	{
		sort_an(mte, min, max);
		i = 0;
		while (i < n/3)
		{
			reverse(2, mte);
			i++;
		}
		sort_a(mte, min +pivot_2, max);
		sort_b(mte, min +pivot_1, min + pivot_2 -1);
		sort_b(mte, min, min +pivot_1 -1);
	}
}

static void sort_an(t_mte *mte, int min, int max)
{
	const int n = max - min + 1; //pivot 정해주기
	const int pivot_1 = n/3 + n%3;
	const int pivot_2 = n/3 * 2 + n%3;
	int i;

	i = 0;
	while (i < n)
	{
		if (mte->arr[mte->divide - 1].label < min + pivot_1) //small은 스택 a하단에 
			push(1, mte);
		else if (mte->arr[mte->divide - 1].label < min + pivot_2 &&
			mte->arr[mte->divide - 1].label >= min + pivot_1) // mid는 스택 b 하단에
		{
			push(1, mte);
			rotate(1, mte);
		}
		else if(mte->arr[mte->divide - 1].label >= min + pivot_2) // big은 스택 b상단에
			rotate(0, mte);
		i++;
	}
}

void sort_b(t_mte *mte, int min, int max)
{
	const int	n = max -min +1;

	if (n == 1)
		push(0, mte);
	else if (n == 2)
	{
		if (mte->arr[mte->divide].label < mte->arr[mte->divide +1].label)
			swap(1, mte);
		push(0, mte);
		push(0, mte);
	}
	else if (n == 3)
		optimize3_b(mte);
	else if (n > 3)
		sort_bn(mte, min, max);
}

static void sort_bn(t_mte *mte, int min, int max)
{
	const int	n = max -min +1;
	const int	pivot_1 = n/3;
	const int	pivot_2 = n/3 *2;
	int			i;

	i = 0;
	while (i < n)
	{
		if (mte->arr[mte->divide].label < min +pivot_1)
			rotate(1, mte);
		else if (mte->arr[mte->divide].label >= min +pivot_1 &&
			mte->arr[mte->divide].label < min +pivot_2)
		{
			push(0, mte);
			rotate(0, mte);
		}
		else if (mte->arr[mte->divide].label >= min +pivot_2)
			push(0, mte);
		i++;
	}
	sort_bn_sub(mte, min, max, n);
}

static void sort_bn_sub(t_mte *mte, int min, int max, int n)
{
	const int	pivot_1 = n/3;
	const int	pivot_2 = n/3 *2;
	int			i;

	sort_a(mte, min +pivot_2, max);
	i = 0;
	while (i < n/3)
	{
		reverse(2, mte);
		i++;
	}
	sort_a(mte, min +pivot_1, min +pivot_2 -1);
	sort_b(mte, min, min +pivot_1 -1);
}
