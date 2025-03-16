#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	isnum(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int check_string(char *str)
{
	int	i;
	int sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (!isnum(str[i]))
		{
			if (str[i] == '+' || str[i] == '-')
			{
				++sign;
				if (i != 0 && isnum(str[i -1]))
					return (0);
			}
			else
				return (0);
		}
		++i;
	}
	if (sign > 1)
		return (0);
	return (1);
}

void	*strclear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free (str[i]);
	return (free(str), NULL);
}

long	ft_atoi(char *str)
{
	int		i;
	long	num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return (sign * num);
}
