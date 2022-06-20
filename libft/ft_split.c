#include "libft.h"

/* split - splits string s using character c as delimiter. NULL terminated */
/* ptr** does needs null termination as mentioned in question */
/* Protected - null *s */
static size_t	wordsize(char const *str, char c, size_t i)
{
	size_t	word;

	word = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		word++;
		i++;
	}
	return (word);
}

static size_t	numofstr(char const *str, char c)
{
	size_t	word;
	int		i;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			word++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**ptr;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	ptr = malloc(sizeof(char *) * (numofstr(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			ptr[j] = ft_substr(s, i, wordsize(s, c, i));
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}
