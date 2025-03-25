/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:27:20 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/26 01:40:08 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*first_to_last;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	first_to_last = *stack;
	if (!temp->next)
		return ;
	temp = temp->next;
	*stack = NULL;
	*stack = temp;
	while (temp->next)
		temp = temp->next;
	temp->next = first_to_last;
	temp->next->next = NULL;
}

void	ra(t_list **stack)
{
	write (1, "ra\n", 3);
	rotate(stack);
}

void	rb(t_list **stack)
{
	write (1, "rb\n", 3);
	rotate(stack);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	write (1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
}
