#include "libft.h"

/* strlen - returns number of character in a string */
/* Cannot be protected, will cause compile error (test agaim) */
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
