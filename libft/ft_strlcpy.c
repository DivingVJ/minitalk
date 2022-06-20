#include "libft.h"

/* strlcpy - Copies up to size - 1 fr src to dest. Null ended. */
/* Returns full src size */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	else if (len + 1 <= size)
	{
		ft_memcpy(dest, src, len + 1);
	}
	else if (len + 1 > size)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}
