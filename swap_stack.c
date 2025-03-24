/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:04:32 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/24 18:19:16 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*pre_end;

	pre_end = *stack;
	while (pre_end && pre_end->next->next)
		pre_end = pre_end->next;
	temp = pre_end;
	pre_end = pre_end->next;
	pre_end->next = temp;
	pre_end->next->next = NULL;
}

void	sa(t_list **stack)
{
	write (1, "sa\n", 3);
	swap_stack(stack);
}

void	sb(t_list **stack)
{
	write (1, "sb\n", 3);
	swap_stack(stack);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	write (1, "ss\n", 3);
	swap_stack(stack_a);
	swap_stack(stack_b);
}
