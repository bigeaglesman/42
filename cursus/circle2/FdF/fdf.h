#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>

// mlx 구조체
typedef struct	s_vars {
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
	int	x;
	int	y;
}t_dot;

void	draw_rectangle(t_data *data, const int x_c, const int y_c, const int width);
void	draw_line(t_data *data, const int x1, const int y1, const int x2, const int y2);
void	draw_line_x(t_data *data, const int x1, const int y1, const int x2, const int y2);
void	draw_line_y(t_data *data, const int x1, const int y1, const int x2, const int y2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_hook();
int		key_hook(int keycode, t_vars *vars);
void	prtimage();

#endif