#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = content;
	list->next = NULL;
	return (list);
}

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
