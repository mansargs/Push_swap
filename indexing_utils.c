/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:29:48 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/23 19:29:49 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_unique(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			++j;
		}
	}
	return (1);
}

static void	fill(int *arr, t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		arr[i] = *((int *)(stack_a->data));
		stack_a = stack_a->next;
		++i;
	}
}

static int	find_index(int num, int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (num == arr[i])
			return (i);
	}
	return (-1);
}

static void	put_indexes(t_list *list, int *arr, int n)
{
	int	idx;

	while (list)
	{
		idx = find_index(*((int *)list->data), arr, n);
		list->index = idx;
		list = list->next;
	}
}

int	copy_to_array(t_list *stack_a)
{
	int	n;
	int	*arr;

	n = ft_lstsize(stack_a);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	fill(arr, stack_a);
	if (!check_unique(arr, n))
		return (free(arr), 0);
	quicksort(arr, 0, n - 1);
	put_indexes(stack_a, arr, n);
	return (free(arr), 1);
}
