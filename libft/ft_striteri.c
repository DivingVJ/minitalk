#include "libft.h"

/* striteri - applies func f to each character in string s */
/* main - calls func 1 with params + ptr to func 2  with 2 params */
/* func 2 - accepts 2 params from this func */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
