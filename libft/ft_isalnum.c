#include "libft.h"

/* isalnum - returns 0 if not alphanumeric */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
