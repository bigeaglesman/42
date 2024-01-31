/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:31:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/31 16:27:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat *mat_create(int row, int col)
{
	int		i;
	t_mat	*p_mat;

	i = 0;
	p_mat = (t_mat *)malloc(sizeof(t_mat));
	p_mat->col = col;
	p_mat->row = row;
	p_mat->mat = (int **)malloc(sizeof(int *) * row);
	while (i < row)
	{
		p_mat-> mat[i] = (int *)ft_calloc(col,sizeof(int));
		if (!p_mat->mat[i])
			exit(0);
		i++;
	}
	return (p_mat);
}

// void mat_free(t_mat *mat)

// int **a, int **b, int a_rows, int b_cols, int b_rows

t_mat *mat_multiple(t_mat *a, t_mat *b)
{
	int	i;
	int j;
	int	k;
	t_mat *c;

	i = 0;
	c = mat_create(a->row, b->col);
	while (i < a->row)
	{
		j = 0;
		while (j < b->col)
		{
			k = 0;
			while (k < b->row)
			{
				c->mat[i][j] += a->mat[i][k] * b->mat[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

// void	n_trans_mat(int **mat, int theta, char n)
// {
// 	if (n == 'x')
// 		x_trans_mat(mat, theta);
// 	else if (n == 'y')
// 		y_trans_mat(mat, theta);
// 	else if (n == 'z')
// 		z_trans_mat(mat, theta);
// 	else
// 		exit (0);
// }