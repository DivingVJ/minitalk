#include "libft.h"

/* strjoin - returns ptr to new string after  cat 2 strings */
/* Protected - null *s1 & *s2 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sumlen;
	char	*joinptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	joinptr = malloc(sizeof(char) * (sumlen + 1));
	if (joinptr == NULL)
		return (NULL);
	*joinptr = '\0';
	ft_strlcat(joinptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(joinptr, s2, sumlen + 1);
	return (joinptr);
}
