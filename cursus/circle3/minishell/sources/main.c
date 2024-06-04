/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:27:47 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/04 17:05:47 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*rl_gets(void);

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		argc_err();
	set_signals();
	set_terminal();
	while (1)
	{
		char *cmd = rl_gets();
			builtin_cd("test");
	}
	exit(1);
}

static char	*rl_gets(void)
{
	char	*command;

	command = readline("minishell$ \033[s");
	if (command && *command)
	{
		add_history(command);
		free(command);
	}
	else
	{
		printf("\033[u\033[1B\033[1Aexit\n");
		exit(0);
	}
	return (command);
}
