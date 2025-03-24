/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:04:32 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/24 19:31:32 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_list **stack)
{
	t_list	*pre_last;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	pre_last = *stack;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = pre_last;
	if (pre_last == *stack)
		*stack = last;
	else
	{
		t_list *temp = *stack;
		while (temp->next != pre_last)
			temp = temp->next;
		temp->next = last;
	}
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
