/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:31:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/04 17:18:44 by ycho2            ###   ########.fr       */
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
	p_mat->mat = (double **)malloc(sizeof(double *) * row);
	while (i < row)
	{
		p_mat-> mat[i] = (double *)ft_calloc(col,sizeof(double));
		if (!p_mat->mat[i])
			exit(0);
		i++;
	}
	return (p_mat);
}

void	mat_free(t_mat *p_mat)
{
	int i;

	i = 0;
	while (i < p_mat->row)
	{
		free (p_mat->mat[i]);
		i++;
	}
	free (p_mat->mat);
	free (p_mat);
}

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
	// mat_free(a);
	// mat_free(b);
	return (c);
}

// t_mat	*n_rot_mat(t_mat *p_mat, int theta, char n)
// {
// 	if (n == 'x')
// 		return (x_rot_mat(p_mat, theta));
// 	else if (n == 'y')
// 		return (y_rot_mat(p_mat, theta));
// 	else if (n == 'z')
// 		return (z_rot_mat(p_mat, theta));
// 	else
// 		exit (0);
// }

t_mat	*x_rot_mat(t_mat *p_mat, int theta)
{
	t_mat *x_rot;
	t_mat *out_mat;
	const double cos_theta = cos(theta* PI/180);
	const double sin_theta = sin(theta* PI/180);

	x_rot = mat_create(3, 3);
	x_rot->mat[0][0] = 1;
	x_rot->mat[1][1] = cos_theta;
	x_rot->mat[1][2] = -sin_theta;
	x_rot->mat[2][1] = sin_theta;
	x_rot->mat[2][2] = cos_theta;
	out_mat = mat_multiple(x_rot, p_mat);
	// mat_free(x_rot);
	// mat_free(p_mat);
	return (out_mat);
}

t_mat	*y_rot_mat(t_mat *p_mat, int theta)
{
	t_mat *y_rot;
	t_mat *out_mat;
	const double cos_theta = cos(theta* PI/180);
	const double sin_theta = sin(theta* PI/180);

	y_rot = mat_create(3, 3);
	y_rot->mat[1][1] = 1;
	y_rot->mat[0][0] = cos_theta;
	y_rot->mat[0][2] = -sin_theta;
	y_rot->mat[2][0] = sin_theta;
	y_rot->mat[2][2] = cos_theta;
	out_mat = mat_multiple(y_rot, p_mat);
	// mat_free(y_rot);
	// mat_free(p_mat);
	return (out_mat);
}

t_mat	*z_rot_mat(t_mat *p_mat, int theta)
{
	t_mat *z_rot;
	t_mat *out_mat;
	const double cos_theta = cos(theta* PI/180);
	const double sin_theta = sin(theta* PI/180);

	z_rot = mat_create(3, 3);
	z_rot->mat[2][2] = 1;
	z_rot->mat[0][0] = cos_theta;
	z_rot->mat[0][1] = -sin_theta;
	z_rot->mat[1][0] = sin_theta;
	z_rot->mat[1][1] = cos_theta;
	out_mat = mat_multiple(z_rot, p_mat);
	// mat_free(z_rot);
	// mat_free(p_mat);
	return (out_mat);
}

t_mat	*unit_mat_create(int n)
{
	t_mat *unit_mat;
	int i;

	i = 0;
	unit_mat = mat_create(n ,n);
	while (i < n)
	{
		unit_mat->mat[i][i] = 1;
		i++;
	}
	return (unit_mat);
}
