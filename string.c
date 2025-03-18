#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	while (i < srcsize && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

static size_t	count_char(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		++len;
	while (num / 10)
	{
		num /= 10;
		++len;
	}
	return (len);
}

static int	minus_case(char *str, int *len, int *num)
{
	int	limit;

	limit = 0;
	if (*num < 0)
	{
		*str = '-';
		limit = 1;
		if (*num == -2147483648)
		{
			*num = (*num + 1) * -1;
			*(str + --(*len)) = '8';
			*num /= 10;
		}
		else
			*num *= -1;
	}
	return (limit);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*str;
	int		limit;

	len = count_char(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + len) = '\0';
	limit = minus_case(str, &len, &num);
	while (len > limit)
	{
		*(str + len - 1) = (num % 10) + '0';
		num = num / 10;
		--len;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		num = 10 * num + (str[i++] - 48);
	return (sign * num);
}

void	strclear(char ***str)
{
	int	i;

	if (!str || !*str)
		return;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
		i++;
	}

	free(*str);
	*str = NULL;
}

