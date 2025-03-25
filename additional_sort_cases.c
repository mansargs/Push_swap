/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sort_cases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:41:10 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/25 17:00:01 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_number(t_list **stack)
{
	t_list	*list;

	list = *stack;
	if (list->index < list->next->index && list->next->index < list->next->next->index)
	{
		rra(stack);
		sa(stack);
	}
	else if (list->index < list->next->index && list->next->index > list->next->next->index)
	{
		rra(stack);
		rra(stack);
	}
	else if (list->index > list->next->index && list->index < list->next->next->index)
		rra(stack);
	else if (list->index < list->next->index && list->index > list->next->next->index)
	{
		ra(stack);
		sa(stack);
	}
	else
		sa(stack);
}

void	min_in_top(t_list **stack, int min)
{
	int		i;
	t_list	*min_index;

	i = 1;
	min_index = *stack;
	while (min_index)
	{
		if (min_index->index == min)
			break ;
		++i;
		min_index = min_index->next;
	}
	if (i <= ft_lstsize(*stack) / 2)
		while (i--)
			ra(stack);
	else
		while (i++ != ft_lstsize(*stack))
			rra(stack);
}

void	four_and_five(t_list **stack_a, t_list **stack_b)
{
	int	counter;
	int	i;
	int	min;

	counter = ft_lstsize(*stack_a) - 3;
	min = -1;
	i = -1;
	while (++i < counter)
	{
		min_in_top(stack_a, ++min);
		pb(stack_b, stack_a);
	}
	print_stack(*stack_a);
	printf("\n-----------------\n");
	print_stack(*stack_b);
	sort_three_number(stack_a);
	while(i--)
		pa(stack_a, stack_b);
}
