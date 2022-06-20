#include "libft.h"
#include <stdio.h>

/* strtrim - returns string with characters in set trimmed from front & back */
/* Protected - null *s1. Also chars in set are tested in any order */
static size_t	chk_f(char const *s1, char const *set, size_t lstr, size_t lset)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < lstr)
	{
		while (j < lset)
		{
			if (s1[i] != set[j])
			{
				j++;
			}
			else if (s1[i] == set[j])
			{
				j = 0;
				i++;
			}
		}
		return (i);
		i++;
	}
	return (0);
}

static size_t	chk_b(char const *s1, char const *set, size_t lstr, size_t lset)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (lstr > 0)
	{
		while (j < lset)
		{
			if (s1[lstr - 1] != set[j])
			{
				j++;
			}
			else if (s1[lstr - 1] == set[j])
			{
				lstr--;
				if (lstr != 0)
					j = 0;
			}
		}
		return (lstr);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	lenset;
	size_t	lenstr;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	lenstr = ft_strlen(s1);
	lenset = ft_strlen(set);
	start = chk_f(s1, set, lenstr, lenset);
	end = lenstr - chk_b(s1, set, lenstr, lenset);
	if (lenstr == start)
		return (ft_strdup(""));
	ptr = ft_substr(s1, start, lenstr - start - end);
	return (ptr);
}
