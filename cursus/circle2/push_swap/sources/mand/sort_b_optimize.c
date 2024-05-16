/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_optimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:50:52 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/23 12:02:48 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize3_b_sub1(t_mte *mte);
static void	optimize3_b_sub2(t_mte *mte);

void	optimize3_b(t_mte *mte)
{
	if (mte->arr[mte->divide].label < mte->arr[mte->divide +1].label)
		optimize3_b_sub1(mte);
	else
		optimize3_b_sub2(mte);
}

static void	optimize3_b_sub1(t_mte *mte)
{
	if (mte->arr[mte->divide +1].label < mte->arr[mte->divide +2].label)
	{
		rotate(1, mte);
		swap(1, mte);
		push(0, mte);
		push(0, mte);
		reverse(1, mte);
		push(0, mte);
	}
	else if (mte->arr[mte->divide].label < mte->arr[mte->divide +2].label)
	{
		swap(1, mte);
		push(0, mte);
		swap(1, mte);
		push(0, mte);
		push(0, mte);
	}
	else
	{
		swap(1, mte);
		push(0, mte);
		push(0, mte);
		push(0, mte);
	}
}

static void	optimize3_b_sub2(t_mte *mte)
{
	if (mte->arr[mte->divide + 1].label > mte->arr[mte->divide +2].label)
	{
		push(0, mte);
		push(0, mte);
		push(0, mte);
	}
	else if (mte->arr[mte->divide].label > mte->arr[mte->divide +2].label)
	{
		push(0, mte);
		swap(1, mte);
		push(0, mte);
		push(0, mte);
	}
	else
	{
		push(0, mte);
		swap(1, mte);
		push(0, mte);
		swap(0, mte);
		push(0, mte);
	}
}
