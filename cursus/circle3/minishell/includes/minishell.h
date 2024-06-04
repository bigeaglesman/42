/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:20:51 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/04 16:38:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include "libft.h"

// signal
void	set_signals(void);

// terminal
void	set_terminal(void);

// error
void	argc_err(void);

//builtin
void	builtin_cd(char *dest);

#endif