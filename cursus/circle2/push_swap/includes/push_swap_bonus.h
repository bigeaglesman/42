/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:20:12 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 19:24:51 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_data
{
	int	number;
	int	label;
}t_data;

typedef struct s_mte
{
	int		divide;
	int		size;
	t_data	*arr;
}t_mte;

void	push(int to, t_mte *mte);
void	swap(int stack, t_mte *mte);
void	rotate(int stack, t_mte *mte);
void	reverse(int stack, t_mte *mte);
void	print_command(int command, int stack);
void	exec_input(char *input, t_mte *mte);

#endif