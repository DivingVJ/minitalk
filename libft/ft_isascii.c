#include "libft.h"

/* isascii - checks if the argument passed is an aascii character or not */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
