#include "libft.h"

/* lstdelone - deletes content pointed by lst. Frees ptr lst. */
/* Linked List will be disconnected, next is assigned to next node */
/* Reconnection to be done in main else it will be lost */
/* Protection  check for null pointer  or no del function*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}
