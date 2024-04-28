/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:37:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 16:13:20 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(int stack, t_mte *mte)
{
	t_data		temp_data;
	int			i;

	if ((stack == 0 || stack == 2) && mte->divide > 1)
	{
		temp_data = mte->arr[0];
		i = 0;
		while (i < mte->divide -1)
		{
			mte->arr[i] = mte->arr[i +1];
			i++;
		}
		mte->arr[mte->divide -1] = temp_data;
	}
	if ((stack == 1 || stack == 2) && mte->divide < mte->size -1)
	{
		temp_data = mte->arr[mte->size -1];
		i = mte->size -1;
		while (i > mte->divide)
		{
			mte->arr[i] = mte->arr[i -1];
			i--;
		}
		mte->arr[mte->divide] = temp_data;
	}
}
