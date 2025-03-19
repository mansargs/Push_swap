#include "push_swap.h"

int	find_index(int num, int *arr, int size)
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

void	put_indexes(t_list *list, int *arr, int n)
{
	int	idx;

	while (list)
	{
		idx = find_index(*((int *)list->data), arr, n);
		list->index = idx;
		list = list->next;
	}
	free(arr);
}