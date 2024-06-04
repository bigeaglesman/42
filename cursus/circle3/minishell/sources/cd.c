/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 00:29:13 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/04 17:05:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_err(char *dest);

void	builtin_cd(char *dest)
{
	int	flag;

	flag = chdir(dest);
	if (flag != 0)
		cd_err(dest);
	exit(0);
}

static void	cd_err(char *dest)
{
	char	*shell_cmd;
	char	*err_msg;

	shell_cmd = ft_strjoin("minishell: cd: ", dest);
	err_msg = ft_strjoin(shell_cmd, ": ");
	free(shell_cmd);
	shell_cmd = ft_strjoin(err_msg, strerror(errno));
	write(2, shell_cmd, 200);
	exit(1);
}
