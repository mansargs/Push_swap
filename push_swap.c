/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:09:52 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/26 18:09:08 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	check_and_add(argc, argv, &stack_a);
	if (!stack_a)
		return (write (2, "Error\n", 6), 1);
	if (!copy_to_array(stack_a))
		return (ft_lstclear(&stack_a), write (2, "Error\n", 6), 1);
	//print_stack(stack_a);
	//printf("\n_____\n");
	//print_stack(stack_b);
	//pb(&stack_b, &stack_a);
	//pa(&stack_a, &stack_b);
	 if (is_sorted(stack_a))
	 	return (ft_lstclear(&stack_a), 0);
	 else
	 	sort_stack(&stack_a, &stack_b);
	//print_stack(stack_a);
	//printf("\n_____\n");
	//print_stack(stack_b);
	return (0);
}
