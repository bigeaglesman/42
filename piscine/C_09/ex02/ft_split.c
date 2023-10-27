/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:22:55 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/13 20:17:59 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		ft_is_sep(char str_i, char *to_find);
void	ft_sep_str(char **seperated_str, char *str, char *charset, int cnt);

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**seperated_str;
	int		len;
	int		i;

	i = 0;
	cnt = 1;
	len = ft_strlen(str);
	if (ft_is_sep(str[i], charset) == 1)
			cnt = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset) == 1)
			if (ft_is_sep(str[i + 1], charset) == 0 && str[i + 1] != 0)
				cnt++;
		i++;
	}
	seperated_str = (char **)malloc(sizeof(char *) * cnt + 1);
	if (seperated_str == 0)
		return (0);
	ft_sep_str(seperated_str, str, charset, cnt);
	return (seperated_str);
}

void	ft_sep_str(char **seperated_str, char *str, char *charset, int cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < cnt)
		seperated_str[i++] = (char *)malloc(ft_strlen(str) + 1);
	seperated_str[i] = 0;
	i = 0;
	while (i < cnt)
	{
		j = 0;
		if (ft_is_sep(str[j], charset) == 1)
		{
			str++;
			continue ;
		}
		while (ft_is_sep(str[j], charset) == 0 && str[j] != 0)
		{
			seperated_str[i][j] = str[j];
			j++;
		}
		seperated_str[i++][j] = 0;
		str += ++j;
	}
}

int	ft_is_sep(char str_i, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == str_i)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
