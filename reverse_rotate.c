/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:01:44 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/24 18:18:36 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
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

void	rra(t_list **stack)
{
	write (1, "rra\n", 4);
	reverse_rotate(stack);
}

void	rrb(t_list **stack)
{
	write (1, "rra\n", 4);
	reverse_rotate(stack);
}

void	rrr(t_list	**stack_a, t_list	**stack_b)
{
	write (1, "rrr\n", 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
