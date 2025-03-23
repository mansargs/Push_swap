/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenovo <lenovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:34:00 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/23 15:57:17 by lenovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_list *start)
{
	if (!start)
	{
		printf("NULL");
		return ;
	}
	while (start)
	{
		printf("data --->%d\taddress ---->%p\tindex ---->%d\n", *(int *)start->data, start->next, start->index);
		start = start->next;
	}
}

