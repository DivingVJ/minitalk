#include "libft.h"

/* strrchr - returns pointer to the last occurence of c */
char	*ft_strrchr(const char *str, int c)
{
	int		size;
	char	*ptr;

	size = (int)ft_strlen(str);
	while (size > -1)
	{
		if (str[size] == (char)c)
		{
			ptr = (char *)&str[size];
			return (ptr);
		}
		size--;
	}
	return (NULL);
}
