#include "libft.h"

/* memcpy - copies the first n chars from src to dest.  */
/* No overlap allowed. Null dest & src - undefined */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	destination = (char *)dest;
	source = (const char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
