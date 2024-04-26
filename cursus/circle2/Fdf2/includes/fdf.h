/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:07:18 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/26 21:29:05 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>

# ifndef PI
#  define PI 3.1415926
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

// mlx 구조체
typedef struct s_vars {
	void		*mlx;
	void		*win;
}t_vars;

// image data 구조체
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

// 행렬 구조체
typedef struct s_mat
{
	int		row;
	int		col;
	double	**mat;
}t_mat;

// 좌표 구조체
typedef struct s_dot
{
	int	z_val;
	int	color;
}t_dot;

typedef struct s_map
{
	int		col;
	int		row;
	t_dot	*dot_arr;
}t_dot;


// draw
// void	draw_rectangle(t_data *data, const int x_c, const int y_c, const int width);
void	draw_line(t_data *data, t_mat *a, t_mat *b);
void	draw_line_y(t_data *data, t_mat *a, t_mat *b);
void	draw_line_x(t_data *data, t_mat *a, t_mat *b);
void	draw_cube(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_hook();
int		key_hook(int keycode, t_vars *vars);
void	prtimage();
 
// error
void	fd_error();

// parsing & checking
int		extension_validity(char *file);
t_dot	**read_map(char *argv);

//mat_utils 
t_mat	*mat_create(int row, int col);
t_mat	*unit_mat_create(int n);
t_mat	*mat_multiple(t_mat *a, t_mat *b);
// t_mat	*n_rot_mat(t_mat *p_mat, int theta, char n);
t_mat	*x_rot_mat(t_mat *p_mat, int theta);
t_mat	*y_rot_mat(t_mat *p_mat, int theta);
t_mat	*z_rot_mat(t_mat *p_mat, int theta);
t_mat	*n_mat_proj(t_mat *p_mat, char n);
t_mat	*mat_par_mov(t_mat *p_mat, int x, int y, int z);

#endif