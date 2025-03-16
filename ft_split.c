#include "push_swap.h"

static int	count_word(char *str, char c)
{
	int	count;
	int	inside;

	count = 0;
	while (str && *str)
	{
		while (*str == c)
			++str;
		inside = 0;
		while (*str && *str != c)
		{
			if (!inside)
			{
				inside = 1;
				++count;
			}
			++str;
		}
	}
	return (count);
}

static void	clear(char **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(result[i]);
	free(result);
}

void	ft_strncpy(char *dest, char *src, int len)
{
	int i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

static int	fill(char **result, char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	while (str && *str)
	{
		while (*str == c)
			++str;
		len = 0;
		while (*str && *str != c)
		{
			++str;
			++len;
		}
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!result[i])
			return (clear(result, i), 0);
		ft_strncpy(result[i], str - len, len);
		++i;
	}
	return (1);
}

char	**ft_split(char *str, char c)
{
	int		count;
	char	**result;

	if (!str)
		return (NULL);
	count = count_word(str, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = NULL;
	if (count)
		if (!fill(result, str, c))
			return (NULL);
	return (result);
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", argc);
	(void) argv;
	char **res;

	res = ft_split(argv[1], ' ');
	int n = count_word(argv[1], ' ');
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", res[i]);
		free (res[i]);
	}
	free(res);
	return (0);
}
	*/
