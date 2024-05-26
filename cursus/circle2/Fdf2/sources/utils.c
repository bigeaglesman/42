/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:09 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/21 14:04:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_open(char	*file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror ("file open failed");
		exit (1);
	}
	else
		return (fd);
}

void	check_col(int col, int col_chk)
{
	if (col != col_chk)
	{
		ft_printf("map column error\n");
		exit(1);
	}
}
