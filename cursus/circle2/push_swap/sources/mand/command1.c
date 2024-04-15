/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:51:30 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/15 16:38:57 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_sub(t_mte *mte, int a, int b);

void push(int to, t_mte *mte)
{
	if (to == 0)
	{
		if (mte->divide < mte->size)
			mte->divide++;
	}
	else if (to == 1)
	{
		if (mte->divide > 0)
			mte-> divide--;
	}
	print_command(0, to);
}

void swap(int stack, t_mte *mte)
{
	const int	divide = mte->divide;

	if ((stack == 0 || stack == 2) && divide > 1)
		swap_sub(mte, divide -1, divide -2);
	if ((stack == 1 || stack == 2) && divide < mte->size -1)
		swap_sub(mte, divide, divide +1);
	print_command(1, stack);
}

static void swap_sub(t_mte *mte, int a, int b)
{
	const t_data	temp_data = mte->arr[a];

	mte->arr[a] = mte->arr[b];
	mte->arr[b] = temp_data;
}

void print_command(int command, int stack)
{
	if (command == 0)
		ft_printf("p");
	else if (command == 1)
		ft_printf("s");
	else if (command == 2)
		ft_printf("r");
	else if (command == 3)
		ft_printf("rr");
	if (stack == 0)
		ft_printf("a\n");
	else if (stack == 1)
		ft_printf("b\n");
	else if (stack == 2)
	{
		if (command == 1)
			ft_printf("s\n");
		else
			ft_printf("r\n");
	}
}
