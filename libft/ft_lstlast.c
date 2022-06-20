#include "libft.h"

/* lstlast - traverses the list till null and returns the last node */
/* protected return null if lst is null */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
