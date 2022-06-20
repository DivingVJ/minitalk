#include "libft.h"

/* putnbr_base - opens an external file and writes in int in a secfied base */
static int	check_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] <= ' ' || base[i] > '~')
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_b_fd( unsigned long nbr, char *base, int fd)
{
	unsigned long	unsgnum;
	unsigned int	blen;
	int				len;

	blen = 0;
	len = 0;
	if (fd == -1)
		return (0);
	unsgnum = nbr;
	blen = ft_strlen(base);
	if (check_base(base) == 1)
	{
		if (unsgnum >= blen)
		{
			len = len + ft_putnbr_b_fd(unsgnum / blen, base, fd);
			len = len + ft_putnbr_b_fd(unsgnum % blen, base, fd);
		}
		else
		{
			len = len + ft_putchar_fd(base[unsgnum], fd);
		}
	}
	return (len);
}
