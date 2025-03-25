/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:09:32 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/26 01:28:36 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_pop(t_list **push, t_list **pop)
{
	t_list *top;

	if (!pop || !*pop)
		return ;
	top = *pop;
	*pop = (*pop)->next;
	ft_lstadd_front(push, top);
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
