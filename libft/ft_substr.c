#include "libft.h"

/* substr - returns pointer to substring from start, length of len */
/* Protected if str is NULL. Checks if start & len dont go beyond str */
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*subptr;

	i = 0;
	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	if (start > size)
		start = size;
	if (len > size - start)
		len = size - start;
	subptr = (char *)malloc(len + 1);
	if (subptr == NULL)
		return (NULL);
	while (i < len)
	{
		subptr[i] = str[start];
		i++;
		start++;
	}
	subptr[i] = '\0';
	return (subptr);
}
