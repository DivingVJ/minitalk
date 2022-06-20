#include "libft.h"

/* lstadd_back - adds element new back of the list. */
/* Protected if lst is null point lst to new */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (node != NULL)
		node->next = new;
	else
		*lst = new;
}
