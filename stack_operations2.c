/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:01:44 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/23 20:24:50 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_list **stack)
{
	t_list	*temp;
	t_list	*pre_last;

	if (!stack || !*stack)
		return ;
	pre_last = *stack;
	if (!pre_last->next)
		return ;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	temp = pre_last;
	pre_last->next->next = *stack;
	*stack = pre_last->next;
	temp->next = NULL;
}

void	rrr(t_list	**stack_a, t_list	**stack_b)
{
	rra_rrb(stack_a);
	rra_rrb(stack_b);
}
