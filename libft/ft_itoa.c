#include "libft.h"

/* itoa - returns string converted from integer L to R. Allows for  -/+  */
/* digit - finds out how many digits. 0  has 1 digit */
/* putnumber - formats number with -ve and adds characters to string */
static int	digit(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		num = num * -1;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*putnumber(char *ptr, int n, int size, int negsign)
{
	ptr[size + negsign] = '\0';
	if (negsign == 1)
		ptr[0] = '-';
	while (size > 0)
	{
		ptr[size + negsign - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*strptr;
	int		negsign;
	int		flag;

	negsign = 0;
	flag = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = n + 1;
			flag = 1;
		}
		n = n * -1;
		negsign = 1;
	}
	strptr = malloc(sizeof(char) * (digit(n) + negsign + 1));
	if (strptr == NULL)
		return (NULL);
	strptr = putnumber(strptr, n, digit(n), negsign);
	if (flag == 1)
		strptr[10] = '8';
	return (strptr);
}
