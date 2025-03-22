#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*Stack_A;
	//t_list	*Stack_B;
	int		*arr;
	int		n;

	Stack_A = NULL;
	//Stack_B = NULL;
	Stack_A =  check_and_add(argc, argv, Stack_A);
	if (!Stack_A)
		return (write (2, "Error\n", 6), 1);
	n = ft_lstsize(Stack_A);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (ft_lstclear(&Stack_A), write (2, "Error\n", 6), 1);
	if (!copy_to_array(n, arr, Stack_A))
		return (ft_lstclear(&Stack_A), write (2, "Error\n", 6), 1);
	put_indexes(Stack_A, arr, n);

	while (Stack_A)
	{
		printf("\ndata --> %d\taddres ----->%p\tindex --->%d", *((int *)Stack_A->data), Stack_A->next, Stack_A->index);
		Stack_A = Stack_A->next;
	}
	return (0);
}
