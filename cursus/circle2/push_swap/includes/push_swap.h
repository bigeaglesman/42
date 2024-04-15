/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:15:24 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/15 16:36:55 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_data
{
	int number;
	int label;
}t_data;

typedef struct s_mte
{
	int	divide;
	int size;
	t_data *arr;
}t_mte;

void push(int to, t_mte *mte);
void swap(int stack, t_mte *mte);
void rotate(int stack, t_mte *mte);
void reverse(int stack, t_mte *mte);
void print_command(int command, int stack);