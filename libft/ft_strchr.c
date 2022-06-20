#include "libft.h"

/* strchr - returns pointer to the first occurence of c */
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
		{
			ptr = (char *)&str[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
