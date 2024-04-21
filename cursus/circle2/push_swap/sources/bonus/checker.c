/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:18:24 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/21 12:31:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int main(int argc, char **argv)
{
	t_mte *mte;
	char *command;

	if (argc == 1)
		exit (1);
	mte = init_mte(argc, argv);
	command = get_next_line(0);
	while (command != -1)
	{
		check
	}
	exit(0);
}


static t_mte *init_mte(int argc, char **argv)
{
	t_mte 	*mte;
	char	**arr_string;
	int		size;

	mte = (t_mte *)malloc(sizeof(t_mte));
	if (!mte)
		exit (1);
	if (argc == 2)
	{
		size = 0;
		arr_string = ft_split(argv[1], ' ');
		while (arr_string[size])
			size++;
		init_arr(size, arr_string, mte);
	}
	else
	{
		mte->arr = (t_data *)malloc(sizeof(t_data) * mte->size);
		if (!mte->arr)
			exit (1);
		init_arr(argc -1, argv +1, mte);
	}
	return (mte);
}

static void init_arr(int size, char **arr , t_mte *mte)
{
	int i;
	int arr_i;

	mte->size = size;
	mte->divide = size;
	mte->arr = (t_data *)malloc(sizeof(t_data)*size);
	if (!mte->arr)
		exit(1);
	i = 0;
	while (i < mte->size)
	{
		mte->arr[i].number = ft_atoi(arr[size -1 -i]);
		mte->arr[i].label = 0;
		arr_i = 0;
		while (arr_i < i)
		{
			arr_labeling(i, arr_i, mte);
			arr_i++;
		}
		i++;
	}
	split_free(arr);
}

static void arr_labeling(int i, int arr_i, t_mte *mte)
{
	if (mte->arr[i].number == mte->arr[arr_i].number)
		{
			ft_printf("Error duplicate number\n");
			exit(1);
		}
	else if (mte->arr[i].number > mte->arr[arr_i].number)
		mte->arr[i].label++;
	else
		mte->arr[arr_i].label++;
}
