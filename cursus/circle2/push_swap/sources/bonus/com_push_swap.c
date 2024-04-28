/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:51:30 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 17:18:16 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_sub(t_mte *mte, int a, int b);

void	push(int to, t_mte *mte)
{
	if (to == 0)
	{
		if (mte->divide < mte->size)
			mte->divide++;
	}
	else if (to == 1)
	{
		if (mte->divide > 0)
			mte-> divide--;
	}
}

void	swap(int stack, t_mte *mte)
{
	const int	divide = mte->divide;

	if ((stack == 0 || stack == 2) && divide > 1)
		swap_sub(mte, divide -1, divide -2);
	if ((stack == 1 || stack == 2) && divide < mte->size -1)
		swap_sub(mte, divide, divide +1);
}

static void	swap_sub(t_mte *mte, int a, int b)
{
	const t_data	temp_data = mte->arr[a];

	mte->arr[a] = mte->arr[b];
	mte->arr[b] = temp_data;
}
