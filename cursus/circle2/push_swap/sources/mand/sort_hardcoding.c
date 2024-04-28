/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hardcoding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:16:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 17:43:35 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort_3(t_mte *mte)
{
	if (mte->arr[mte->divide -1].label == 0)
	{
		if (mte->arr[mte->divide -2].label == 2)
		{
			swap(0, mte);
			rotate(0, mte);
		}
	}
	else if (mte->arr[mte->divide -1].label == 1)
	{
		if (mte->arr[mte->divide -2].label == 2)
			reverse(0, mte);
		else
			swap(0, mte);
	}
	else if (mte->arr[mte->divide -1].label == 2)
	{
		if (mte->arr[mte->divide -2].label == 1)
		{
			swap(0, mte);
			reverse(0, mte);
		}
		else if (mte->arr[mte->divide -2].label == 0)
			rotate(0, mte);
	}
}

void	hard_sort_5(t_mte *mte)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mte->arr[mte->divide -1].label == 3
			|| mte->arr[mte->divide -1].label == 4)
			push(1, mte);
		else
			rotate(0, mte);
		i++;
	}
	hard_sort_3(mte);
	if (mte->arr[mte->divide].label == 4)
		swap(1, mte);
	push(0, mte);
	rotate(0, mte);
	push(0, mte);
	rotate(0, mte);
}
