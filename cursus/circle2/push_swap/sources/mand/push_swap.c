/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:41 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/15 19:00:48 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_mte *init_mte(int argc, char **argv);
static void init_arr(int argc, char **argv , t_mte *mte);
static void sort_nA(t_mte *mte, int min, int max);
static void sort_nB(t_mte *mte, int min, int max);

int main(int argc, char **argv)
{
	t_mte *mte;

	if (argc <= 2)
		exit (1);
	mte = init_mte(argc, argv);
	if (argc == 4)
	{
		if (mte)
	}
	else if (argc == 6)
	{

	}
	else
	// for (int i = 0; i < mte->size; i++)
	// 	printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	// printf ("divide : %d size: %d\n", mte->divide, mte->size);

	// printf("\n\nTest push\n");
	// push(0, mte);
	// push(1,mte);
	// push(1,mte);
	// push(1,mte);
	// for (int i = 0; i < mte->size; i++)
	// 	printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	// printf ("divide : %d size: %d\n", mte->divide, mte->size);

	// printf("\n\nTest swap\n");
	// swap(0, mte);
	// swap(1, mte);
	// // swap(2, mte);
	// for (int i = 0; i < mte->size; i++)
	// 	printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	// printf ("divide : %d size: %d\n", mte->divide, mte->size);

	// printf("\n\nTest rotate\n");
	// rotate(0, mte);
	// rotate(1, mte);
	// for (int i = 0; i < mte->size; i++)
	// 	printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	// printf ("divide : %d size: %d\n", mte->divide, mte->size);

	// printf("\n\nTest reverse\n");
	// reverse(0, mte);
	// reverse(1, mte);
	// for (int i = 0; i < mte->size; i++)
	// 	printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	// printf ("divide : %d size: %d\n", mte->divide, mte->size);

		sort_nA(mte, 0, argc - 2);
	// for (int i = 0; i < mte->size; i++)
	// 	printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	// printf ("divide : %d size: %d\n", mte->divide, mte->size);
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

static void sort_nA(t_mte *mte, int min, int max)
{
	const int n = max - min + 1; //pivot 정해주기
	const int pivot_1 = n/3 + n%3;
	const int pivot_2 = n/3 * 2 + n%3;
	int i;

	if (n == 2) //n이 1인 경우는 건드리지 않는다 n이 2인 경우는 a스택 위 2대의 값을 비교해서 정렬한다
	{
		if (mte->arr[mte->divide-1].label > mte->arr[mte->divide-2].label)
			swap(0, mte);
	}
	else if (n >= 3)
	{
		i = 0;
		while (i < n)
		{
			if (mte->arr[mte->divide - 1].label < min + pivot_1) //small은 스택 a하단에 
				push(1, mte);
			else if (mte->arr[mte->divide - 1].label < min + pivot_2 &&
				mte->arr[mte->divide - 1].label >= min + pivot_1) // mid는 스택 b 하단에
			{
				push(1, mte);
				rotate(1, mte);
			}
			else if(mte->arr[mte->divide - 1].label >= min + pivot_2) // big은 스택 b상단에
				rotate(0, mte);
			i++;
		}
		i = 0;
		while (i < n/3)
		{
			reverse(2, mte);
			i++;
		}
		sort_nA(mte, min +pivot_2, max);
		sort_nB(mte, min +pivot_1, min + pivot_2 -1);
		sort_nB(mte, min, min +pivot_1 -1);
	}
}

static void sort_nB(t_mte *mte, int min, int max)
{
	const int	n = max -min +1;
	const int	pivot_1 = n/3;
	const int	pivot_2 = n/3 *2;
	int			i;

	if (n == 1)
		push(0, mte);
	else if (n == 2)
	{
		if (mte->arr[mte->divide].label < mte->arr[mte->divide +1].label)
			swap(1, mte);
		push(0, mte);
		push(0, mte);
	}
	else if (n >= 3)
	{
		i = 0;
		while (i < n)
		{
			if (mte->arr[mte->divide].label < min +pivot_1)
				rotate(1, mte);
			else if (mte->arr[mte->divide].label >= min +pivot_1 &&
				mte->arr[mte->divide].label < min +pivot_2)
			{
				push(0, mte);
				rotate(0, mte);
			}
			else if (mte->arr[mte->divide].label >= min +pivot_2)
				push(0, mte);
			i++;
		}
		sort_nA(mte, min +pivot_2, max);
		i = 0;
		while (i < n/3)
		{
			reverse(2, mte);
			i++;
		}
		sort_nA(mte, min +pivot_1, min +pivot_2 -1);
		sort_nB(mte, min, min +pivot_1 -1);
	}
}
