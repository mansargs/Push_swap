/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:48:11 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/25 19:43:06 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	max_in_top(t_list **stack, int max)
{
	int		i;
	t_list	*max_index;
	int		size;

	i = 0;
	max_index = *stack;
	size = ft_lstsize(*stack);

	while (max_index)
	{
		if (max_index->index == max)
			break;
		++i;
		max_index = max_index->next;
	}

	// Debug print
	printf("Moving max index %d to top. Current position: %d, Stack size: %d\n", max, i, size);

	if (i <= size / 2)
	{
		while (i--) // Rotate `i` times
			ra(stack);
	}
	else
	{
		int moves = size - i; // Correct number of reverse rotates
		while (moves--)
			rra(stack);
	}
}



void	butterfly(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		len;
	t_list	*last;
	int		n;
	int		counter;

	size = ft_lstsize(*stack_a);
	len = size;
	n = sqrt(len) - log2(len) + 1;
	counter = 0;
	while (size != 3)
	{
		// printf("\nStack A\n");
		// print_stack(*stack_a);
		// printf("\nStack B\n");
		// print_stack(*stack_b);
		if (!*stack_a)
			return ;
		last = *stack_a;
		while (last->next)
			last = last->next;
		if (last->index <= counter)
		{
			pb(stack_b, stack_a);
			rrb(stack_b);
			++counter;
			--size;
		}
		else if (last->index <= counter + n)
		{
			pb(stack_b, stack_a);
			++counter;
			--size;
		}
		else
			rra(stack_a);
	}
	sort_three_number(stack_a);
	while (++size <= len)
	{
		max_in_top(stack_b, size -1);
		pa(stack_a, stack_b);
	}
}
