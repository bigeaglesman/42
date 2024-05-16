/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:41:49 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/23 11:34:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bn(t_mte *mte, int min, int max);
static void	sort_b_small(t_mte *mte, int n);

void	sort_b(t_mte *mte, int min, int max)
{
	const int	n = max - min + 1;
	const int	pivot_1 = n / 3;
	const int	pivot_2 = n / 3 * 2;
	int			i;

	if (n > 3)
	{
		sort_bn(mte, min, max);
		sort_a(mte, min + pivot_2, max);
		i = 0;
		while (i < n / 3)
		{
			reverse(2, mte);
			i++;
		}
		sort_a(mte, min + pivot_1, min + pivot_2 -1);
		sort_b(mte, min, min + pivot_1 -1);
	}
	else
		sort_b_small(mte, n);
}

static void	sort_b_small(t_mte *mte, int n)
{
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
}

static void	sort_bn(t_mte *mte, int min, int max)
{
	const int	n = max - min + 1;
	const int	pivot_1 = n / 3;
	const int	pivot_2 = n / 3 * 2;
	int			i;

	i = 0;
	while (i < n)
	{
		if (mte->arr[mte->divide].label < min + pivot_1)
			rotate(1, mte);
		else if (mte->arr[mte->divide].label >= min + pivot_1
			&& mte->arr[mte->divide].label < min + pivot_2)
		{
			push(0, mte);
			rotate(0, mte);
		}
		else if (mte->arr[mte->divide].label >= min + pivot_2)
			push(0, mte);
		i++;
	}
}
