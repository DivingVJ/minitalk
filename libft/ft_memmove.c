#include "libft.h"

/* memmove - copies n bytes of src into dest. Memory location can overlap */
/* Memory address increases L to R */
static void	copy_forward(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		n--;
		dest[n] = src[n];
	}	
}

static void	copy_backward(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}	
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	if (dest == src || n == 0)
		return (dest);
	destination = (char *)dest;
	source = (const char *)src;
	if (destination > source)
		copy_forward(destination, source, n);
	else if (destination < source)
		copy_backward(destination, source, n);
	return (destination);
}
