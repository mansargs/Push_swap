/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenovo <lenovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:13:02 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/22 16:14:27 by lenovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(char	*itoa, char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-')
	{
		++i;
		if (itoa[j] == '-')
			++j;
		while (str[i] == '0')
			++i;
		if (str[i] == '\0')
			--i;
	}
	while (str[i] && itoa[j])
	{
		if (str[i] != itoa[j])
			return (0);
		++i;
		++j;
	}
	return (1);
}

int	check(char	*str)
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
	else
		return (free(itoa), 1);
}

int	add(char *str, t_list **Stack_A)
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
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			return (strclear(&split), NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (strclear(&split), NULL);
		j = -1;
		while (split[++j])
		{
			if (!check(split[j]))
				return (strclear(&split), NULL);
			if (!add(split[j], &Stack_A))
				return (strclear(&split), NULL);
		}
		strclear(&split);
	}
	return (Stack_A);
}
