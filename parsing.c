#include "push_swap.h"

int parse(int argc, char *argv[])
{
	char **numbers;
	int i;
	int j;
	long num;

	i = argc;
	while (--i)
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
		{
			printf("hi");
			return (0);
		}
		while (numbers[j])
		{
			if (!check_string(numbers[j]))
				return (0);
			num = ft_atoi(numbers[j]);
			if (num < INT_MIN || num > INT_MAX)
				return (0);
			printf("%ld", num);
			++j;
		}
		printf("\n-----------------------------------------\n");
	}
	return (1);
}
