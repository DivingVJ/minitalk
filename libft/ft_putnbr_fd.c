#include "libft.h"

/* putnbr_fd - opens an external file and writes in  int n */
int	ft_putnbr_fd(int n, int fd)
{
	int		len;

	len = 0;
	if (fd == -1)
		return (0);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len = len + ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
	{
		len = len + ft_putnbr_fd(n / 10, fd);
		len = len + ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		len = len + ft_putchar_fd((n + '0'), fd);
	}
	return (len);
}
