/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:42:00 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 18:41:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	exec_input_sub(char *input, t_mte *mte);

void	exec_input(char *input, t_mte *mte)
{
	if (ft_strncmp(input, "pa\n", 3) == 0)
		push(0, mte);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		push(1, mte);
	else if (ft_strncmp(input, "sa\n", 3) == 0)
		swap(0, mte);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		swap(1, mte);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		swap(2, mte);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		rotate(0, mte);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		rotate(1, mte);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		rotate(2, mte);
	else
		exec_input_sub(input, mte);
}

static void	exec_input_sub(char *input, t_mte *mte)
{
	if (ft_strncmp(input, "rra\n", 4) == 0)
		reverse(0, mte);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		reverse(1, mte);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		reverse(2, mte);
	else
	{
		ft_printf("Error wrong input\n");
		exit(1);
	}
}
