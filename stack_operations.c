/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenovo <lenovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:27:20 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/23 14:57:47 by lenovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	swap_data_index(t_list *list1, t_list *list2)
{
	int	content;
	int	idx;

	content = *((int *)(list1)->data);
	idx = list1->index;
	*(int *)list1->data = *(int *)list2->data;
	list1->index = list2->index;
	list2->index = idx;
	*(int *)list2->data = content;
 }
*/

void	sa_sb(t_list **stack)
{
	t_list *temp;

	while (*stack && (*stack)->next->next)
		*stack = (*stack)->next;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->next->next = NULL;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_sb(stack_a);
	sa_sb(stack_b);
}



