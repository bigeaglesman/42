/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:18:24 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 20:22:41 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void		check_sorted(t_mte *mte);
static t_mte	*init_mte(int argc, char **argv);
static void		init_arr(int size, char **arr, t_mte *mte, const int flag);
static void		arr_labeling(int i, int arr_i, t_mte *mte);

int	main(int argc, char **argv)
{
	t_mte	*mte;
	char	*input;

	if (argc == 1)
		exit (1);
	mte = init_mte(argc, argv);
	input = get_next_line(0);
	while (input)
	{
		exec_input(input, mte);
		free(input);
		input = get_next_line(0);
	}
	check_sorted(mte);
	exit(0);
}

static t_mte	*init_mte(int argc, char **argv)
{
	t_mte	*mte;
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
		init_arr(size, arr_string, mte, 1);
	}
	else
		init_arr(argc -1, argv +1, mte, 0);
	return (mte);
}

static void	init_arr(int size, char **arr, t_mte *mte, const int flag)
{
	int	i;
	int	arr_i;

	mte->size = size;
	mte->divide = size;
	mte->arr = (t_data *)malloc(sizeof(t_data) * size);
	if (!mte->arr)
		exit(1);
	i = 0;
	while (i < mte->size)
	{
		mte->arr[i].number = ft_atoi(arr[size - 1 - i]);
		mte->arr[i].label = 0;
		arr_i = 0;
		while (arr_i < i)
		{
			arr_labeling(i, arr_i, mte);
			arr_i++;
		}
		i++;
	}
	if (flag == 1)
		split_free(arr);
}

static void	arr_labeling(int i, int arr_i, t_mte *mte)
{
	if (mte->arr[i].number == mte->arr[arr_i].number)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else if (mte->arr[i].number > mte->arr[arr_i].number)
		mte->arr[i].label++;
	else
		mte->arr[arr_i].label++;
}

static void	check_sorted(t_mte *mte)
{
	int	i;

	i = 0;
	while (i < mte->size -1)
	{
		if (mte->arr[i].label != mte->arr[i +1].label +1)
		{
			ft_printf("KO\n");
			exit(0);
		}
		i++;
	}
	if (i == mte->size -1 && mte->size == mte->divide)
	{
		ft_printf("OK\n");
		exit(0);
	}
	else
	{
		ft_printf("KO\n");
		exit(0);
	}
}
