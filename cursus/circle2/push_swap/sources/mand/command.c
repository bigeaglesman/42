/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:51:30 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/09 18:02:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(int to, t_mte *mte)
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

void swap(int stack, t_mte *mte)
{
	const int	divide = mte->divide;
	t_data		temp_data;

	if (stack == 0 && divide > 1)
	{
		temp_data = mte->arr[divide -1];
		mte->arr[divide -1] = mte->arr[divide-2];
		mte->arr[divide -2] = temp_data;
	}
	else if (stack == 1 && divide < mte->size -1)
	{
		temp_data = mte->arr[divide];
		mte->arr[divide] = mte->arr[divide +1];
		mte->arr[divide +1] = temp_data;
	}
	else if (stack == 2)
	{
		swap(0, mte);
		swap(1, mte);
	}
}

void rotate(int stack, t_mte *mte)
{
	const int	divide = mte->divide;
	t_data		temp_data;
	int			i;

	if (stack == 0 && divide > 1)
	{
		temp_data = mte->arr[divide-1];
		i = divide -1;
		while (i > 0)
		{
			mte->arr[i] = mte->arr[i -1];
			i--;
		}
		mte->arr[0] = temp_data;
	}
	else if (stack == 1 && divide < mte->size -1)
	{
		temp_data = mte->arr[divide];
		i = divide;
		while (i < mte->size -1)
		{
			mte->arr[i] = mte->arr[i +1];
			i++;
		}
		mte->arr[mte->size -1] = temp_data;
	}
	else if (stack == 2)
	{
		rotate(0, mte);
		rotate(1, mte);
	}
}

void reverse(int stack, t_mte *mte)
{
	const int	divide = mte->divide;
	t_data		temp_data;
	int			i;

	if (stack == 0 && divide > 1)
	{
		temp_data = mte->arr[0];
		i = 0;
		while (i < divide -1)
		{
			mte->arr[i] = mte->arr[i +1];
			i++;
		}
		mte->arr[divide -1] = temp_data;
	}
	else if (stack == 1 && divide < mte->size -1)
	{
		temp_data = mte->arr[mte->size -1];
		i = mte->size -1;
		while (i > divide)
		{
			mte->arr[i] = mte->arr[i -1];
			i--;
		}
		mte->arr[divide] = temp_data;
	}
	else if (stack == 2)
	{
		reverse(0, mte);
		reverse(1, mte);
	}
}
