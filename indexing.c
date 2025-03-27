/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:29:48 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/27 19:29:55 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_list **stack, char ***split, int num)
{
	t_list	*temp;
	int		index_last;

	if (!(*stack)->next)
		return ;
	temp = *stack;
	index_last = 0;
	while (temp->next)
	{
		if (*(int *)temp->data == num)
			error_handle(stack, split, VALIDATION_ERROR);
		if (*(int *)temp->data > num)
			++temp->index;
		else
			++index_last;
		if (temp->next->next)
			temp = temp->next;
		else
			break ;
	}
	temp->next->index = index_last;
}
