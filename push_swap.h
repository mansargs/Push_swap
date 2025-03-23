/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenovo <lenovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:15:24 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/23 14:46:43 by lenovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
	int				index;
}					t_list;

// Work with strings
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	strclear(char ***str);

int		check_and_add(int argc, char *argv[], t_list **stack_a);

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

int		copy_to_array(t_list *list);


void	quicksort(int	*arr, int low, int high);

int		is_sorted(t_list *stack_a);

void	print_stack(t_list *start);
void	sa_sb(t_list **stack);

#endif
