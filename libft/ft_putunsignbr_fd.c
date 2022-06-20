#include "libft.h"

/* putunsignbr_fd - opens an external file and writes in  unsigned int n */
int	ft_putunsignbr_fd(unsigned long n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (fd == -1)
		return (0);
	if (n > 9)
	{
		len = len + ft_putunsignbr_fd(n / 10, fd);
		len = len + ft_putunsignbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		len = len + ft_putchar_fd(c, fd);
	}
	return (len);
}
