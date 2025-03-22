/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validator_Utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenovo <lenovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:13:02 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/22 21:24:54 by lenovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(char *itoa, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-')
	{
		if (itoa[j] == '-')
			++j;
		++i;
	}
	while (str[i] == '0')
		++i;
	while (itoa[j] == '0')
		j++;
	while (str[i] && itoa[j])
	{
		if (str[i] != itoa[j])
			return (0);
		++i;
		++j;
	}
	return (str[i] == '\0' && itoa[j] == '\0');
}

int	no_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
	return (1);
}

int	check(char *str)
{
	int		i;
	int		num;
	char	*itoa;

	i = 0;
	num = ft_atoi(str);
	itoa = ft_itoa(num);
	if (str[i] == '+')
		++i;
	while (str[i] == '0')
		++i;
	if (str[i] == '\0')
		--i;
	if (!compare(itoa, str + i))
		return (free(itoa), 0);
	return (free(itoa), 1);
}

int	add(char *str, t_list **stack_a)
{
	int		num;
	int		*ptr;
	t_list	*new_node;

	num = ft_atoi(str);
	ptr = (int *)malloc(sizeof(int));
	if (!ptr)
		return (0);
	*ptr = num;
	new_node = ft_lstnew(ptr);
	if (!new_node)
		return (0);
	ft_lstadd_back(stack_a, new_node);
	return (1);
}

int	check_and_add(int argc, char *argv[], t_list **stack_a)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0' || no_digit(argv[i]))
			return (ft_lstclear(stack_a), 0);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (ft_lstclear(stack_a), 0);
		j = -1;
		while (split[++j])
		{
			if (!check(split[j]))
				return (ft_lstclear(stack_a), strclear(&split), 0);
			if (!add(split[j], stack_a))
				return (ft_lstclear(stack_a), strclear(&split), 0);
		}
		strclear(&split);
	}
	return (1);
}
