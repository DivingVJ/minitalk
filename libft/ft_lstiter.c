#include "libft.h"

/* lstiter - iterates function f on content of each element   */
/* Starting from element pointed by lst */
/* Protection check for null pointer  */
void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (lst == NULL || f == NULL)
		return ;
	while ((lst) != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
