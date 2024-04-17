/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:41 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/17 12:02:16 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_mte *init_mte(int argc, char **argv);
static void init_arr(int argc, char **argv , t_mte *mte);

int main(int argc, char **argv)
{
	t_mte *mte;

	if (argc <= 2)
		exit (1);
	mte = init_mte(argc, argv);
	if (argc == 4)
		hard_sort_3(mte);
	else if (argc == 6)
		hard_sort_5(mte);
	else
		sort_a(mte, 0, argc - 2);
}

static t_mte *init_mte(int argc, char **argv)
{
	t_mte *mte;

	mte = (t_mte *)malloc(sizeof(t_mte));
	if (!mte)
		exit (1);
	mte->size = argc - 1;
	mte->divide = mte->size;
	mte->arr = (t_data *)malloc(sizeof(t_data) * mte->size);
	if (!mte->arr)
		exit (1);
	init_arr(argc, argv, mte);
	return (mte);
}

static void init_arr(int argc, char **argv , t_mte *mte)
{
	int i;
	int arr_i;

	i = 0;
	while (i < mte->size)
	{
		mte->arr[i].number = ft_atoi(argv[argc -1 -i]);
		mte->arr[i].label = 0; 
		arr_i = 0;
		while (arr_i < i)
		{
			if (mte->arr[i].number >= mte->arr[arr_i].number)
				mte->arr[i].label++;
			else
				mte->arr[arr_i].label++;
			arr_i++;
		}
		i++;
	}
}
