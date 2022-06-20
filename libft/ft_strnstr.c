#include "libft.h"

/* strnstr - looks for to_find in str in the first len chars. Returns  */
/* Protect against len more than  strlen(str)  */
char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	find_len;

	i = 0;
	find_len = ft_strlen(to_find);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	if (find_len == 0)
		return ((char *)str);
	while (i < len && (i + find_len - 1) < len)
	{
		if (ft_strncmp(str, to_find, find_len) == 0)
		{
			return ((char *)str);
		}
		str++;
		i++;
	}
	return (NULL);
}
