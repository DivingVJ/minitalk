#include "libft.h"

/* lstadd_front - adds element new in front of list. Moves lst to the front*/
/* No protection if lst null just adds new element before*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
