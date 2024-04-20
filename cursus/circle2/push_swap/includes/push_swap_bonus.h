/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:20:12 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/21 03:24:32 by ycho2            ###   ########.fr       */
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
