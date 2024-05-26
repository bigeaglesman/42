/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:07:18 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/21 13:50:27 by ycho2            ###   ########.fr       */
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

# ifndef PI
#  define PI 3.1415926
# endif

# ifndef ROOT2
#  define ROOT2 1.4
# endif

typedef struct s_vars {
	void		*mlx;
	void		*win;
}t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_dot
{
	int	x_val;
	int	y_val;
	int	z_val;
	int	color;
}t_dot;

typedef struct s_map
{
	int		col;
	int		row;
	t_dot	**mat;
}t_map;

typedef struct s_cnv_dot
{
	double	x_val;
	double	y_val;
	int		color;
}t_cnv_dot;

typedef struct s_draw
{
	double		gradient;
	t_cnv_dot	start;
	t_cnv_dot	dest;
	int			win_height;
	int			win_width;
	int			w;
	int			h;
	int			color;
}t_draw;

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

void		draw_line(t_data *data, t_cnv_dot s, t_cnv_dot e, t_trans *t);
t_cnv_dot	**trans_map(t_map *map, t_trans *trans);

int			exit_hook(void);
int			key_hook(int keycode, t_vars *vars);

int			file_open(char	*file_name);
void		check_col(int col, int col_chk);

int			extension_validity(char *file);
t_map		*parse_map(char *map_file);

#endif