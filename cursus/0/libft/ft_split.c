#include "libft.h"

static size_t count_words(char const *s, char c)
static char *speprate_words(char const *s, char c, size_t n_words)

char **ft_split(char const *s, char c)
{
	size_t	n_words;
	int	flag;
	char	**split;

	n_words = count_words(s,c);
	arr = (char **)malloc(sizeof(char *)*(n_words + 1));
	if (!arr)
		return (0);
	
}

static size_t count_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while(s[i])
	{
		if (s[i] == c && flag == 0);
		else if (s[i] != c && flag ==0)
		{
			flag = 1;
			cnt++;
		}
		else if (s[i] == c && flag == 1)
			flag = 0;
		else if (s[i] != c && flag == 1);
		i++;
	}
}

static char *speprate_words(char const *s, char c, size_t n_words, char **arr)
{
	
}
