/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:56:14 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/17 11:54:26 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void optimize3_a_sub(t_mte *mte);
static void optimize3_b_sub1(t_mte *mte);
static void optimize3_b_sub2(t_mte *mte);

void optimize3_a(t_mte *mte)
{
	if (mte->arr[mte->divide -1].label < mte->arr[mte->divide -2].label) // 021 012 120
	{
		if (mte->arr[mte->divide -2].label < mte->arr[mte->divide -3].label)
			return ;
		else if (mte->arr[mte->divide -1].label < mte->arr[mte->divide -3].label) // 021
		{
			push(1, mte);
			swap(0, mte);
			push(0, mte);
		}
		else // 120
		{
			push(1,mte);
			swap(0, mte);
			push(0, mte);
			swap(0, mte);
		}
	}
	else // 102 201 210
		optimize3_a_sub(mte);
}

static void optimize3_a_sub(t_mte *mte)
{
	if (mte->arr[mte->divide -2].label > mte->arr[mte->divide -3].label) // 210
	{
		push(1, mte);
		rotate(0,mte);
		push(0, mte);
		swap(0, mte);
		reverse(0, mte);
		swap(0, mte);
	}
	else if (mte->arr[mte->divide -1].label > mte->arr[mte->divide -3].label) // 201
	{
		push(1, mte);
		rotate(0, mte);
		push(0, mte);
		swap(0, mte);
		reverse(0, mte);
	}
	else // 102
		swap(0, mte);
}

void optimize3_b(t_mte *mte)
{
	if (mte->arr[mte->divide].label < mte->arr[mte->divide +1].label) // 021 012 120
		optimize3_b_sub1(mte);
	else // 102 201 210
		optimize3_b_sub2(mte);
}

static void optimize3_b_sub1(t_mte *mte)
{
	if (mte->arr[mte->divide +1].label < mte->arr[mte->divide +2].label) // 012
	{
		rotate(1, mte);
		swap(1, mte);
		push(0, mte);
		push(0, mte);
		reverse(1, mte);
		push(0, mte);
	}
	else if (mte->arr[mte->divide].label < mte->arr[mte->divide +2].label) // 021
		{
			swap(1, mte);
			push(0, mte);
			swap(1, mte);
			push(0, mte);
			push(0, mte);
		}
	else // 120
	{
		swap(1, mte);
		push(0, mte);
		push(0, mte);
		push(0, mte);
	}
}

static void optimize3_b_sub2(t_mte *mte)
{
	if (mte->arr[mte->divide+1].label > mte->arr[mte->divide +2].label) // 210
	{
		push(0, mte);
		push(0, mte);
		push(0, mte);
	}
	else if (mte->arr[mte->divide].label > mte->arr[mte->divide +2].label) // 201
	{
		push(0, mte);
		swap(1, mte);
		push(0, mte);
		push(0, mte);
	}
	else// 102
	{
		push(0, mte);
		swap(1, mte);
		push(0, mte);
		swap(0, mte);
		push(0, mte);
	}
}