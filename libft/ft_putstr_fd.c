#include "libft.h"

/* putstr_fd - opens an external file and writes in  string s */
/* Protected - null *c */
int	ft_putstr_fd(char *c, int fd)
{
	int	len;

	len = 0;
	if (fd == -1)
		return (0);
	if (c == NULL)
	{
		c = "(null)";
	}
	while (*c != '\0')
	{
		len = len + ft_putchar_fd(*c, fd);
		c++;
	}
	return (len);
}
