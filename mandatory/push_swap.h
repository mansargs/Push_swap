/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:34:20 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/28 11:47:18 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	int				index;
}					t_list;

// Helper functions
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

// Cleaning and program interrupt functions
void	strclear(char ***str);
void	ft_lstclear(t_list **lst);
void	error_handle(t_list **stack, char ***split, int exit_code);

// Validation, stack builder and indexing functions
void	check_and_add(int argc, char *argv[], t_list **stack_a);
void	indexation(t_list **stack, char ***split, int num);

// Functions for linked list managment
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

// Stack operations
void	swap_stack(t_list **stack, char *operation);
void	push_pop(t_list **push, t_list **pop, char *operation);
void	rotate(t_list **stack, char *operation);
void	reverse_rotate(t_list **stack, char *operation);

// sorting
int		is_sorted(t_list *stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_three_number(t_list **stack);
void	four_and_five(t_list **stack_a, t_list **stack_b);
void	butterfly(t_list **stack_a, t_list **stack_b);

#endif
