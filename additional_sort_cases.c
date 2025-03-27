/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sort_cases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:41:10 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/27 04:00:30 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_number(t_list **stack)
{
	t_list	*list;

	list = *stack;
	if (list->index > list->next->index
		&& list->index > list->next->next->index)
	{
		rotate(stack, "ra\n");
		if ((*stack)->index > (*stack)->next->index)
			swap_stack(stack, "sa\n");
	}
	else if (list->index < list->next->index
		&& list->next->index > list->next->next->index)
	{
		reverse_rotate(stack, "rra\n");
		if ((*stack)->index > (*stack)->next->index)
			swap_stack(stack, "sa\n");
	}
	else if (list->index > list->next->index)
		swap_stack(stack, "sa\n");
}

static void	min_in_top(t_list **stack, int min)
{
	int		i;
	int		lenght;
	t_list	*min_index;

	i = 0;
	lenght = ft_lstsize(*stack) - 1;
	min_index = *stack;
	while (min_index)
	{
		if (min_index->index == min)
			break ;
		++i;
		min_index = min_index->next;
	}
	if (i <= lenght / 2)
		while (i--)
			rotate(stack, "ra\n");
	else
		while (i++ <= lenght)
			reverse_rotate(stack, "rra\n");
}

void	four_and_five(t_list **stack_a, t_list **stack_b)
{
	int	counter;
	int	i;
	int	min;

	counter = ft_lstsize(*stack_a) - 3;
	min = -1;
	i = -1;
	if ((*stack_a)->next->index == 0)
		swap_stack(stack_a, "sa\n");
	while (++i < counter)
	{
		min_in_top(stack_a, ++min);
		push_pop(stack_b, stack_a, "pb\n");
	}
	sort_three_number(stack_a);
	while (i--)
		push_pop(stack_a, stack_b, "pa\n");
}
