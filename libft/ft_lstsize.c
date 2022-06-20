#include "libft.h"

/* lstsize - traverses the list till null and returns the size */
/* No protection lst null - size = 0 */
int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}
