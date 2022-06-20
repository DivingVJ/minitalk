#include "libft.h"

/* strdup - duplicates a string. Uses stdlib.h for malloc() */
char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(src);
	dup = malloc(size + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, src, size);
	dup[size] = '\0';
	return (dup);
}
