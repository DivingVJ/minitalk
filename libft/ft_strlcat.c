#include "libft.h"

/* strcat - Cats size - 1 chars from src to dest with null added */
/* Size is full size of string to be created */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	offset;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	offset = destlen;
	if (size < destlen)
		return (size + srclen);
	while ((offset < size - 1) && (src[i] != '\0') && (size != 0))
	{
		dest[offset] = src[i];
		offset++;
		i++;
	}
	dest[offset] = '\0';
	return (destlen + srclen);
}
