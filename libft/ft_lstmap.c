#include "libft.h"

/* lstmap - iterates function f on content of each element   */
/* Adds result to a new list. Protection check for null pointer  */
/* In case malloc fails, entire newlst is to be deleted */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void*))
{
	t_list	*newlst;
	t_list	*node;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	node = NULL;
	newlst = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew((*f)(lst->content));
		tmp = lst->next;
		lst = tmp;
		ft_lstadd_back(&newlst, node);
		if (node == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
	}
	return (newlst);
}
