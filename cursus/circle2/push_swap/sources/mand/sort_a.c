/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:07:55 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/26 10:58:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_small(t_mte *mte, int n);
static void	sort_an(t_mte *mte, int min, int max);

void	sort_a(t_mte *mte, int min, int max)
{
	const int	n = max - min + 1;
	const int	pivot_1 = n / 3 + n % 3;
	const int	pivot_2 = n / 3 * 2 + n % 3;
	int			i;

	if (n > 3)
	{
		sort_an(mte, min, max);
		i = 0;
		while (i < n / 3)
		{
			reverse(2, mte);
			i++;
		}
		sort_a(mte, min + pivot_2, max);
		sort_b(mte, min + pivot_1, min + pivot_2 -1);
		sort_b(mte, min, min + pivot_1 -1);
	}
	else
		sort_a_small(mte, n);
}

static void	sort_a_small(t_mte *mte, int n)
{
	if (n == 2)
	{
		if (mte->arr[mte->divide -1].label > mte->arr[mte->divide -2].label)
			swap(0, mte);
	}
	else if (n == 3)
		optimize3_a(mte);
}

static void	sort_an(t_mte *mte, int min, int max)
{
	const int	n = max - min + 1;
	const int	pivot_1 = n / 3 + n % 3;
	const int	pivot_2 = n / 3 * 2 + n % 3;
	int			i;

	i = 0;
	while (i < n)
	{
		if (mte->arr[mte->divide - 1].label < min + pivot_1)
			push(1, mte);
		else if (mte->arr[mte->divide - 1].label < min + pivot_2
			&& mte->arr[mte->divide - 1].label >= min + pivot_1)
		{
			push(1, mte);
			rotate(1, mte);
		}
		else if (mte->arr[mte->divide - 1].label >= min + pivot_2)
			rotate(0, mte);
		i++;
	}
}
