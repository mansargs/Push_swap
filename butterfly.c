/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:48:11 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/26 03:33:38 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:48:11 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/26 02:40:31 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void max_in_top(t_list **stack, int max)
{
	int i;
	int length;
	t_list *max_index;

	i = 0;
	length = ft_lstsize(*stack);
	max_index = *stack;
	while (max_index)
	{
		if (max_index->index == max)
			break;
		++i;
		max_index = max_index->next;
	}
	if (i <= length / 2)
		while (i--)
			ra(stack);
	else
		while (length-- > i)
			rra(stack);
}

void	butterfly(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		len;
	t_list	*last;
	int		n;
	int		counter;
	int     max;

	size = ft_lstsize(*stack_a);
	len = size;
	n = sqrt(len) + log2(len) - 1;
	counter = 0;
	while (size > 3)
	{
		if (!*stack_a)
			return ;
		last = *stack_a;
		if (last->index <= counter)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			++counter;
			--size;
		}
		else if (last->index <= counter + n)
		{
			pb(stack_b, stack_a);
			++counter;
			--size;
		}
		else
			ra(stack_a);
	}
	sort_three_number(stack_a);
	max = len - 4;
	while (ft_lstsize(*stack_b) > 0)
	{
		max_in_top(stack_b, max);
		pa(stack_a, stack_b);
		max--;
	}
}

