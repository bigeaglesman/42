/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:27:47 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/26 22:05:00 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*command;

	while (1)
	{
		command = readline("minishell$ ");
		printf("argc %d program is %s command is %s\n", argc, argv[0], command);
	}
}