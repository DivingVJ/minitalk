#include "libft.h"

/* putendl_fd - opens an external file and writes in  string c with nextline */
/* Protected - null *c */
void	ft_putendl_fd(char *c, int fd)
{
	int	i;

	i = 0;
	if (fd == -1 || c == NULL)
		return ;
	while (c[i] != '\0')
	{
		write(fd, &c[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
