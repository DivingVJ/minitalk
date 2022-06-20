#include "libft.h"

/* memcmp - compares first n characters for 2 strings. Returns first diff */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				diff;
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	diff = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i < n)
	{	
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}	
	return (diff);
}
