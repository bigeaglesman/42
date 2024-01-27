/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:50:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/18 17:43:32 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

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
char	*ft_strjoin(char *out, t_buf *buf_case, int attach_len);
int		ft_strlen(const char *str);
void	ft_strlcat(char *dest, const char *src, int size);

#endif
