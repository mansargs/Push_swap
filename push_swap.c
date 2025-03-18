#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*Stack_A;
	int		n;

//	Stack_A = (t_list *)malloc(sizeof(t_list) * 1);
//	if (!Stack_A)
//		return (1);
	Stack_A = NULL;
	Stack_A =  check_and_add(argc, argv, Stack_A);
	if (!Stack_A)
		return (write (2, "Error\n", 6), 1);
	n = ft_lstsize(Stack_A);
	printf("%d\n", n);
	while (Stack_A)
    {
        if (Stack_A->data)  // Avoid dereferencing NULL
			printf("%d\t", *((int *)(Stack_A->data)));
        Stack_A = Stack_A->next;
    }
	return (0);
}
