/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:27:20 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/23 20:00:29 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **stack)
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

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_sb(stack_a);
	sa_sb(stack_b);
}

void	pa_pb(t_list **push, t_list **pop)
{
	t_list	*push_last;
	t_list	*pop_prelast;
	t_list	*temp;

	if (!pop || !*pop)
		return ;
	push_last = *push;
	if (push_last)
		while (push_last->next)
			push_last = push_last->next;
	pop_prelast = *pop;
	while (pop_prelast->next && pop_prelast->next->next)
		pop_prelast = pop_prelast->next;
	if (pop_prelast->next)
		temp = pop_prelast->next;
	else
		temp = pop_prelast;
	if (!push_last)
		*push = temp;
	else
		push_last->next = temp;
	if (!pop_prelast->next)
		*pop = NULL;
	else
		pop_prelast->next = NULL;
}

void	ra_rb(t_list **stack)
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

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
}

