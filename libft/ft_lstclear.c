#include "libft.h"

/* lstclear - delete content pointed by lst.  */
/* Repeats for subsequent elements till end */
/* Protection check for null pointer or no del function */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (*lst == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = next;
	}
	*lst = NULL;
}
