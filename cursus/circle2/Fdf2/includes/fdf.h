#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

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
typedef struct	s_vars {
	void		*mlx;
	void		*win;
}t_vars;

// image data 구조체
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

// 좌표 구조체
typedef struct	s_dot
{
	int		z_val;
	int		color;
}t_dot;

// 행렬 구조체
typedef struct	s_mat
{
	int	row;
	int	col;
	double **mat;
}t_mat;

// gnl 구조체
typedef struct	s_buf
{
	char	read_buf[BUFFER_SIZE + 1];
	int		idx;
	int		used;
}t_buf;

typedef struct	s_map
{
	int				row;
	int				col;
	struct s_dot	**map;
}t_map;

// draw
void	draw_rectangle(t_data *data, const int x_c, const int y_c, const int width);
void	draw_line(t_data *data, const int x1, const int y1, const int x2, const int y2);
void	draw_line_x(t_data *data, const int x1, const int y1, const int x2, const int y2);
void	draw_line_y(t_data *data, const int x1, const int y1, const int x2, const int y2);
void	draw_cube(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_hook();
int		key_hook(int keycode, t_vars *vars);
void	prtimage();

// error
void	fd_error();

// parsing & checking
int		extension_validity(char *file);
t_map	*read_map(char *argv);

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

//get_next_line
char	*get_next_line(int fd);
int		ft_read_attach(int fd, char **pout, t_buf *buf_case);

int		ft_read_line(int fd, t_buf *buf_case);
int		ft_attach_nl(char **pout, t_buf *buf_case);
char	*gnl_strjoin(char *out, t_buf *buf_case, int attach_len);
void	gnl_strlcat(char *dest, const char *src, int size);

#endif