/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:34:00 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/27 04:04:14 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	n;

	(void) stack_b;
	n = ft_lstsize(*stack_a);
	if (n == 2)
		swap_stack(stack_a, "sa\n");
	else if (n == 3)
		sort_three_number(stack_a);
	else if (n == 4 || n == 5)
		four_and_five(stack_a, stack_b);
	else
		butterfly(stack_a, stack_b);
}
