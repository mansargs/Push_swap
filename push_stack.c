/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:09:32 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/24 18:13:27 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_pop(t_list **push, t_list **pop)
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

void	pa(t_list **push, t_list **pop)
{
	write (1, "pa\n", 3);
	push_pop(push, pop);
}

void	pb(t_list **push, t_list **pop)
{
	write (1, "pb\n", 3);
	push_pop(push, pop);
}
