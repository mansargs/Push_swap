/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:09:52 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/23 20:10:52 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;

	stack_a = NULL;
	//stack_b = NULL;
	check_and_add(argc, argv, &stack_a);
	if (!stack_a)
		return (write (2, "Error\n", 6), 1);
	if (!copy_to_array(stack_a))
		return (ft_lstclear(&stack_a), write (2, "Error\n", 6), 1);

	printf("\nStack A\n");
	print_stack(stack_a);
	rra_rrb(&stack_a);
	printf("\n_____\n");
	printf("\nStack A\n");
	print_stack(stack_a);
	return (0);
}
