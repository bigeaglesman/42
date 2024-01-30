/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:09 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/30 12:40:41 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;

	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	i = 0;
	while ((temp_s1[i] || temp_s2[i]) && i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int **mat_create(int row, int col)
{
	int i;
	int **mat;

	i = 0;
	mat = (int **)malloc(sizeof(int *)*row);
	while (i < row)
	{
		mat[i] = (int *)calloc(col,sizeof(int));
		if (!mat[i])
			exit(0);
		i++;
	}
	return (mat);
}

int	**mat_multiple(int **a, int **b, int a_rows, int b_cols, int b_rows)
{
	int	i;
	int j;
	int	k;
	int **c;

	c = (int **)malloc(sizeof(int *) * a_rows);
	i = 0;
	while (i < a_rows)
	{
		c[i] = (int *)malloc(sizeof(int) * b_cols);
		j = 0;
		while (j < b_cols)
		{
			k = 0;
			c[i][j] = 0;
			while (k < b_rows)
			{
				c[i][j] += a[i][k]*b[k][j];
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