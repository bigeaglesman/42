/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:07:18 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/14 10:35:19 by ycho2            ###   ########.fr       */
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

# ifndef ROOT2
#  define ROOT2 1.4
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

// 좌표 구조체
typedef struct s_dot
{
	int	x_val;
	int	y_val;
	int	z_val;
	int	color;
}t_dot;

// map구조체
typedef struct s_map
{
	int		col;
	int		row;
	t_dot	**mat;
}t_map;

// 변형 후 맵
typedef struct s_cnv_dot
{
	double	x_val;
	double	y_val;
	int		color;
}t_cnv_dot;

typedef struct s_line_utils
{
	int	w;
	int	h;
	int	start_x;
	int	start_y;
	int	start_color;
	int	final_color;
}t_line_utils;

typedef struct s_trans
{
	double	cosx;
	double	sinx;
	double	cosy;
	double	siny;
	double	cosz;
	double	sinz;
	int		sca_xy;
	int		sca_z;
	int		par_x;
	int		par_y;
	int		win_width;
	int		win_height;
}t_trans;

void	prtimage(t_map *map);

// draw
void	draw_map(t_data *data, t_map *map, t_trans *trans);
void	draw_line(t_data *data, t_cnv_dot start, t_cnv_dot end, t_trans *trans);
t_cnv_dot	**trans_map(t_map *map, t_trans *trans);

void	draw_line_desc_h(t_data *data, t_line_utils line_utils, int final_y, t_trans *trans);
void	draw_line_desc_w(t_data *data, t_line_utils line_utils, int final_x, t_trans *trans);
void	draw_line_asc_h(t_data *data, t_line_utils line_utils, int final_y, t_trans *trans);
void	draw_line_asc_w(t_data *data, t_line_utils line_utils, int final_x, t_trans *trans);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_hook();
int		key_hook(int keycode, t_vars *vars);
 
// error
void	map_file_error(void);

//utils
int		file_open (char	*file_name);

// parsing & checking
int		extension_validity(char *file);
t_map	*parse_map(char *map_file);

#endif