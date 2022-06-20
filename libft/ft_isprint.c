#include "libft.h"

/* isprint - checks if the argument passed is an aascii character or not */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
