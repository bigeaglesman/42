/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:21 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/15 02:53:34 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str);
char	*ft_strdup(char *src);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	i = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*arr;
	int		i;

	i = 0;
	len = 0;
	while (*(src + len))
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (*(src + i))
	{
		*(arr + i) = *(src + i);
		i++;
	}
	*(arr + i) = 0;
	return (arr);
}
