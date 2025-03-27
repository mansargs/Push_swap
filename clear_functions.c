/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:33:18 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/27 02:33:40 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		while (*lst)
		{
			if ((*lst)->data)
			{
				free ((*lst)->data);
				(*lst)->data = NULL;
			}
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

void	strclear(char ***str)
{
	int	i;

	if (!str || !*str)
		return ;
	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
		i++;
	}
	free(*str);
	*str = NULL;
}
