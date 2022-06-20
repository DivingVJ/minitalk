#include "libft.h"

/* isdigit - checks if the argument passed is a digit or not */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
