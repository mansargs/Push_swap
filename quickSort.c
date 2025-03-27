/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:17:14 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/27 03:28:17 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int	*arr, int low, int high)
{
	int	mid;
	int	pivot;
	int	i;
	int	j;

	mid = low + (high - low) / 2;
	swap (arr + mid, arr + high);
	pivot = arr[high];
	i = low - 1;
	j = low - 1;
	while (++j < high)
	{
		if (arr[j] < pivot)
		{
			++i;
			swap(arr + i, arr + j);
		}
	}
	swap(arr + i + 1, arr + high);
	return (i + 1);
}

void	quicksort(int	*arr, int low, int high)
{
	int	pivot;

	if (low >= high)
		return ;
	pivot = partition(arr, low, high);
	quicksort(arr, low, pivot - 1);
	quicksort(arr, pivot + 1, high);
}
