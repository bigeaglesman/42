/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:27:47 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/29 12:31:37 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*rl_gets(void);

int	main(int argc, char **argv, char **envp)
{
	set_signals();
	set_terminal();
	while(rl_gets())
		printf("argc: %d argv[0]: %s envp[0]: %s\n", argc, argv[0], envp[0]);
	exit(1);
}

static char	*rl_gets(void)
{
	char	*command;

	command = readline("minishell$ ");
	if(command && *command)
	{
		add_history(command);
		free(command);
	}
	return(command);
}
