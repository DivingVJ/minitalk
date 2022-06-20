#include "libft.h"

/* calloc - returns ptr to allocated memory ( number * size) */
/* Protected - num & size */
void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
