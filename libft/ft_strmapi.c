#include "libft.h"

/* strmapi - applies func f to each character in string s */
/* main - calls func 1 with params + ptr to func 2  with 2 params */
/* func 2 - accepts 2 params from this func */
/* Protection - null *s */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strptr;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	strptr = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (strptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		strptr[i] = f(i, s[i]);
		i++;
	}
	strptr[i] = '\0';
	return (strptr);
}
