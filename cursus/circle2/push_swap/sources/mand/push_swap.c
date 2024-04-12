/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:41 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/12 16:14:23 by ycho2            ###   ########.fr       */
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
	for (int i = 0; i < mte->size; i++)
		printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	printf ("divide : %d size: %d\n", mte->divide, mte->size);

	printf("\n\nTest push\n");
	push(0, mte);
	push(1,mte);
	push(1,mte);
	push(1,mte);
	for (int i = 0; i < mte->size; i++)
		printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	printf ("divide : %d size: %d\n", mte->divide, mte->size);

	printf("\n\nTest swap\n");
	swap(0, mte);
	swap(1, mte);
	// swap(2, mte);
	for (int i = 0; i < mte->size; i++)
		printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	printf ("divide : %d size: %d\n", mte->divide, mte->size);

	printf("\n\nTest rotate\n");
	rotate(0, mte);
	rotate(1, mte);
	for (int i = 0; i < mte->size; i++)
		printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	printf ("divide : %d size: %d\n", mte->divide, mte->size);

	printf("\n\nTest reverse\n");
	reverse(0, mte);
	reverse(1, mte);
	for (int i = 0; i < mte->size; i++)
		printf("%d %d \n", mte->arr[i].number, mte->arr[i].label); // printf 수정
	printf ("divide : %d size: %d\n", mte->divide, mte->size);
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

// static void sort_nA(t_mte *mte, int min, int max)
// {
// 	const int n = max - min + 1; 
// 	const int pivot_1 = n/3 + n%3;
// 	const int pivot_2 = n/3 * 2 + n%3;
// 	int i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (mte->arr[mte->divide - 1].label < min + pivot_1)
// 			push(1, mte);
// 		else if (mte->arr[mte->divide - 1].label < min + pivot_2 &&
// 			mte->arr[mte->divide - 1].label >= min + pivot_1)
// 		{
// 			push(1, mte);
// 			rotate(1, mte);
// 		}
// 		else if(mte->arr[mte->divide - 1].label >= min + pivot_2)
// 			rotate(0, mte);
// 		i++;
// 	}
	
// }

// static void sort_nB(t_mte mte, int min, int max)
// {

// }