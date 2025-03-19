#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*Stack_A;
	int		*arr;
	int		n;

	Stack_A = NULL;
	Stack_A =  check_and_add(argc, argv, Stack_A);
	if (!Stack_A)
		return (write (2, "Error\n", 6), 1);
	n = ft_lstsize(Stack_A);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (1);
	if (!copy_to_array(n, arr, Stack_A))
		return (write (2, "Error\n", 6), 1);
	for (int i = 0; i < n; ++i)
		printf("%d\t", arr[i]);
	return (0);
}
