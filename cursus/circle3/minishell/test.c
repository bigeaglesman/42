
#include <errno.h>
#include "lib/libft/libft.h"
#include <unistd.h>
#include <string.h>


static void	cd_err(char *dest);
void	builtin_cd(char *dest);

int main(void)
{
	builtin_cd("lib");
}

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

	shell_cmd = ft_strjoin("minishell: cd:", dest);
	err_msg = ft_strjoin(shell_cmd, ": ");
	free(shell_cmd);
	shell_cmd = ft_strjoin(err_msg, strerror(errno));
	write(2, shell_cmd, sizeof(shell_cmd));
	exit(1);
}