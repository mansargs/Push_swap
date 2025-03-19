#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
	int				index;
}					t_list;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Work with strings

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	strclear(char ***str);


t_list		*check_and_add(int argc, char *argv[], t_list *Stack_A);


int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst);

int	copy_to_array(int n, int *arr, t_list *list);

#endif
