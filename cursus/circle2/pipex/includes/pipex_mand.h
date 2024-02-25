/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mand.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:33:35 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/25 11:50:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_MAND_H
# define PIPEX_MAND_H

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

typedef struct s_parsing
{
	char	**envp;
	char	**seped_path_env;
	char	***seped_cmd;
	char	**cmd_path;
	char	*delimiter;
	int		num_cmd;
	int		is_here_doc;
	int		fd1;
	int		fd2;
	int		tmp_fd;
}t_parsing;

int		ft_read_attach(int fd, char **pout, t_buf *buf_case);
int		ft_read_line(int fd, t_buf *buf_case);
int		ft_attach_nl(char **pout, t_buf *buf_case);
char	*gnl_strjoin(char *out, t_buf *buf_case, int attach_len);

char	*get_next_line(int fd);

void	parsing_here_doc(t_parsing *parsing, char **argv, int argc);

void	parsing_main(int argc, char **argv, t_parsing *parsing);

void	cmd_access_err(void);
void	file_open_err(void);
void	malloc_err(void);

#endif