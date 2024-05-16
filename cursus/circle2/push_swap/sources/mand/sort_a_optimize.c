/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_optimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:56:14 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/23 11:59:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize3_a_sub(t_mte *mte);

void	optimize3_a(t_mte *mte)
{
	if (mte->arr[mte->divide -1].label < mte->arr[mte->divide -2].label)
	{
		if (mte->arr[mte->divide -2].label < mte->arr[mte->divide -3].label)
			return ;
		else if (mte->arr[mte->divide -1].label
			< mte->arr[mte->divide -3].label)
		{
			push(1, mte);
			swap(0, mte);
			push(0, mte);
		}
		else
		{
			push(1, mte);
			swap(0, mte);
			push(0, mte);
			swap(0, mte);
		}
	}
	else
		optimize3_a_sub(mte);
}

static void	optimize3_a_sub(t_mte *mte)
{
	if (mte->arr[mte->divide -2].label > mte->arr[mte->divide -3].label)
	{
		push(1, mte);
		rotate(0, mte);
		push(0, mte);
		swap(0, mte);
		reverse(0, mte);
		swap(0, mte);
	}
	else if (mte->arr[mte->divide -1].label > mte->arr[mte->divide -3].label)
	{
		push(1, mte);
		rotate(0, mte);
		push(0, mte);
		swap(0, mte);
		reverse(0, mte);
	}
	else
		swap(0, mte);
}
