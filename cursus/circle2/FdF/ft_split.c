/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:06:20 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/05 13:11:36 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*sep_words(char const *s, int start, int end);
static int		save_words(char const *s, char c, char **split);
static void		split_free(char **split);

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (0);
	if (!save_words(s, c, split))
	{
		split_free(split);
		return (0);
	}
	return (split);
}

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (cnt);
}

static char	*sep_words(char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (0);
	while (i < end - start)
	{
		word[i] = s[i + start];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	save_words(char const *s, char c, char **split)
{
	size_t		i;
	long long	start;
	size_t		nth_word;

	start = -1;
	nth_word = 0;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start != -1)
		{
			split[nth_word] = sep_words(s, start, i);
			if (!split[nth_word])
				return (0);
			start = -1;
			nth_word++;
		}
		i++;
	}
	split[nth_word] = 0;
	return (1);
}

static void	split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
