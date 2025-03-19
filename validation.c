#include "push_swap.h"

int	check(char	*str)
{
	int		i;
	int		j;
	int		num;
	char	*itoa;

	num = ft_atoi(str);
	itoa = ft_itoa(num);
	i = 0;
	j = 0;
	while (str[i] == '+' || str[i] == '0')
		++i;
	if (num < 0)
	{
		while (str[i] == '-' || str[i] == '0')
			++i;
		str[--i] = '-';
	}
	while (str[i] && itoa[j])
	{
		if (str[i] != itoa[j])
			return (free(itoa), 0);
		++i;
		++j;
	}
	if (str[i] == itoa[j])
		return (free(itoa), 1);
	else
		return (free(itoa), 0);
}

int add(char *str, t_list **Stack_A)
{
	int num;
	int *ptr;
	t_list *new_node;

	num = ft_atoi(str);
	ptr = (int *)malloc(sizeof(int));
	if (!ptr)
		return (0);
	*ptr = num;
	// Create a new node for the number
	new_node = ft_lstnew(ptr);
	if (!new_node)
	{
		free(ptr);
		return (0);
	}
	if (*Stack_A != NULL)
	{
		new_node->next = *Stack_A;
	}
	*Stack_A = new_node;

	return (1);
}


t_list	*check_and_add(int argc, char *argv[], t_list *Stack_A)
{
	char	**split;
	int 	i;
	int		j;

	i = argc;
	while(--i)
	{
		if (argv[i][0] == '\0')
			return (strclear(&split), ft_lstclear(&Stack_A), NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (strclear(&split), ft_lstclear(&Stack_A), NULL);
		j = -1;
		while (split[++j]);
		while (--j >= 0)
		{
			if (!check(split[j]))
				return (strclear(&split), ft_lstclear(&Stack_A), NULL);
			if (!add(split[j], &Stack_A))
				return (strclear(&split), ft_lstclear(&Stack_A), NULL);
		}
		strclear(&split);
	}
	return (Stack_A);
}
