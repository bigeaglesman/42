#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

// typedef struct s_buf
// {
// 	char	read_buf[BUFFER_SIZE + 1];
// 	int		idx;
// 	int		used;
// }t_buf;

typedef struct s_parsing
{
	char	**envp;
	char	**seped_path_envp;
	char	***seped_command;
	char	**command_path;
	char	*delimiter;
	int		num_cmd;
	int		is_here_doc;
	int		fd1;
	int		fd2;
}t_parsing;

char	*get_next_line(int fd);
char	*line(char **rest, int fd);
char	*cut(char **rest, int new_pos, int i);
char	*gnl_strrest(char *buff, int new_pos);
int		gnl_strchr(const char *s, int c);
char	*gnl_strndup(char *str, int len);
char	*gnl_strjoin(char *dest, char *append);
size_t	gnl_strlen(const char *str);

char	*get_here_doc_input(char *marker);

void	parsing_main(int argc, char **argv, t_parsing *parsing);
char	**split_path_envp(char **envp);
char	***make_seped_cmd(char **argv_command, int num_cmd);
char	**make_cmd_path(char ***seped_command, char **path_envp, int num_cmd);

void	argument_err();
void	file_access_err();
void	file_open_err();

#endif