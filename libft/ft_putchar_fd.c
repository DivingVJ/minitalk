#include "libft.h"

/* putchar_fd - opens an external file and writes in character c */
int	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return (0);
	write(fd, &c, 1);
	return (1);
}
