/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:15:24 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/17 11:51:16 by ycho2            ###   ########.fr       */
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

void sort_a(t_mte *mte, int min, int max);
void sort_b(t_mte *mte, int min, int max);

void hard_sort_3(t_mte *mte);
void hard_sort_5(t_mte *mte);
void optimize3_a(t_mte *mte);
void optimize3_b(t_mte *mte);
// int hard_sort_4_a(t_mte *mte);
// int hard_sort_4_b(t_mte *mte);