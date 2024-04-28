/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:22:47 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 15:31:24 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_mte *mte);
static void	rotate_b(t_mte *mte);

void	rotate(int stack, t_mte *mte)
{
	const int	divide = mte->divide;

	if ((stack == 0 || stack == 2) && divide > 1)
		rotate_a(mte);
	if ((stack == 1 || stack == 2) && divide < mte->size -1)
		rotate_b(mte);
}

static void	rotate_a(t_mte *mte)
{
	const int		divide = mte->divide;
	const t_data	temp_data = mte->arr[divide -1];
	int				i;

	i = divide -1;
	while (i > 0)
	{
		mte->arr[i] = mte->arr[i - 1];
		i--;
	}
	mte->arr[0] = temp_data;
}

static void	rotate_b(t_mte *mte)
{
	const int		divide = mte->divide;
	const t_data	temp_data = mte->arr[divide];
	int				i;

	i = divide;
	while (i < mte->size -1)
	{
		mte->arr[i] = mte->arr[i +1];
		i++;
	}
	mte->arr[mte->size -1] = temp_data;
}
