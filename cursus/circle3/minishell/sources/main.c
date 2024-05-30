/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:27:47 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/30 22:38:21 by ycho2            ###   ########.fr       */
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
	while(rl_gets())
		printf("argc: %d argv[0]: %s envp[0]: %s\n", argc, argv[0], envp[0]);
	exit(1);
}

static char	*rl_gets(void)
{
	char	*command;

	command = readline("minishell$ \033[s");
	if(command && *command)
	{
		add_history(command);
		free(command);
	}
	else
	{
		printf("\033[u\033[1B\033[1Aexit\n");
		exit(0);
	}
	return(command);
}
