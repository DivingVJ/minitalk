#include "libft.h"

static int	parse_hex(unsigned long ulong, char type)
{
	int		len;
	char	*base;
	char	*cbase;

	base = "0123456789abcdef";
	cbase = "0123456789ABCDEF";
	len = 0;
	if (type == 'p')
	{
		len = ft_putstr_fd("0x", 1);
		len = len + ft_putnbr_b_fd(ulong, base, 1);
	}
	if (type == 'x')
		len = ft_putnbr_b_fd(ulong, base, 1);
	if (type == 'X')
		len = ft_putnbr_b_fd(ulong, cbase, 1);
	return (len);
}

static int	check_format(const char *str, va_list argptr)
{
	int		len;

	len = 0;
	if (*str == 'c')
		len = ft_putchar_fd(va_arg(argptr, int), 1);
	if (*str == 's')
		len = ft_putstr_fd(va_arg(argptr, char *), 1);
	if (*str == 'p')
		len = len + parse_hex((unsigned long)va_arg(argptr, void *), *str);
	if ((*str == 'd') || (*str == 'i'))
		len = ft_putnbr_fd(va_arg(argptr, int), 1);
	if (*str == 'u')
		len = ft_putunsignbr_fd(va_arg(argptr, unsigned int), 1);
	if ((*str == 'x') || (*str == 'X'))
		len = parse_hex(va_arg(argptr, unsigned int), *str);
	if (*str == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		num;
	va_list	argptr;
	int		count;
	int		total;

	num = 0;
	count = 0;
	total = 0;
	va_start(argptr, str);
	while (*str)
	{
		if ((*str == '%') && (*str + 1 != '\0'))
		{
			str++;
			count = check_format(str, argptr);
		}
		else
			num = num + write(1, str, 1);
		total = total + count;
		count = 0;
		str++;
	}
	va_end(argptr);
	return (num + total);
}
