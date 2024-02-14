#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_buf
{
	char	read_buf[BUFFER_SIZE + 1];
	int		idx;
	int		used;
}t_buf;

char	*get_next_line(int fd);
int		ft_read_attach(int fd, char **pout, t_buf *buf_case);

int		ft_read_line(int fd, t_buf *buf_case);
int		ft_attach_nl(char **pout, t_buf *buf_case);
char	*gnl_strjoin(char *out, t_buf *buf_case, int attach_len);
void	gnl_strlcat(char *dest, const char *src, int size);


#endif