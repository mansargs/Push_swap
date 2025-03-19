#include "push_swap.h"

int	check_unique(int *arr, int size)
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int	*arr, int low, int high)
{
	int	mid;
	int	pivot;
	int	i;
	int	j;

	mid = low + (high - low) / 2;
	swap(arr + mid, arr + high);
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

void	quickSort(int	*arr, int low, int high)
{
	int	pivot;

	if (low >= high)
		return ;

	pivot = partition(arr, low, high);

	quickSort(arr, low, pivot - 1);
	quickSort(arr, pivot + 1, high);

}

int	copy_to_array(int n, int *arr, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		arr[i] = *((int *)(list->data));
		list=list->next;
		++i;
	}
	if (!check_unique(arr, n))
		return (free(arr), 0);
	quickSort(arr, 0, n - 1);
	return (1);
}
