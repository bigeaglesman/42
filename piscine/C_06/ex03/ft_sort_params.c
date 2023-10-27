/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:21:00 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/08 22:52:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_argvs(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (argc - i > j)
		{
			if (ft_strcmp(*(argv + j), *(argv + j + 1)) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}		
		i++;
	}
	ft_print_argvs (argc, argv);
}

void	ft_print_argvs(int argc, char **argv)
{
	int	k;
	int	l;

	k = 1;
	while (k < argc)
	{
		l = 0;
		while (*(argv[k] + l))
		{
			write (1, argv[k] + l, 1);
			l++;
		}
		write (1, "\n", 1);
		k++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) > *(s2 + i))
			return (1);
		else if (*(s1 + i) < *(s2 + i))
			return (-1);
		i++;
	}
	return (0);
}
