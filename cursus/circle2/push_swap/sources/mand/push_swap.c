/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:07:24 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/23 00:27:13 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sorted(t_mte *mte);
static void	sort_first(t_mte *mte);

int	main(int argc, char **argv)
{
	t_mte	*mte;

	if (argc == 1)
		exit (1);
	mte = init_mte(argc, argv);
	check_sorted(mte);
	if (mte->size == 3)
		hard_sort_3(mte);
	else if (mte->size == 5)
		hard_sort_5(mte);
	else
		sort_first(mte);
	exit(0);
}

static void	check_sorted(t_mte *mte)
{
	int	i;

	i = 0;
	while (i < mte->size -1)
	{
		if (mte->arr[i].label != mte->arr[i +1].label +1)
			return ;
		i++;
	}
	if (i == mte->size -1)
		exit(0);
}

static void	sort_first(t_mte *mte)
{
	const int	n = mte->size;
	const int	pivot_1 = n / 3 + n % 3;
	const int	pivot_2 = n / 3 * 2 + n % 3;
	int			i;

	i = 0;
	while (i < n)
	{
		if (mte->arr[mte->divide - 1].label < pivot_1)
		{
			push(1, mte);
			rotate(1, mte);
		}
		else if (mte->arr[mte->divide - 1].label < pivot_2
			&& mte->arr[mte->divide - 1].label >= pivot_1)
			push(1, mte);
		else if (mte->arr[mte->divide - 1].label >= pivot_2)
			rotate(0, mte);
		i++;
	}
	sort_a(mte, pivot_2, mte->size -1);
	sort_b(mte, pivot_1, pivot_2 -1);
	sort_b(mte, 0, pivot_1 -1);
}
