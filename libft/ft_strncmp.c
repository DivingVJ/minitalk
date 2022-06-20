#include "libft.h"

/* strncmp - compares first n characters for 2 strings. */
/* Returns the first diff found */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i < n)
		{	
			if (s1[i] != s2[i])
			{
				diff = (unsigned char)s1[i] - (unsigned char)s2[i];
				return (diff);
			}
		}	
		i++;
	}
	return (diff);
}
