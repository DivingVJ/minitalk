#include "libft.h"

/* atoi - returns int converted from string L to R. */
/* Allows many isspace & 1 -/+  */
static int	check_space(const char *str, int i)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negsign;
	int	num;

	i = 0;
	num = 0;
	negsign = 1;
	i = check_space(str, i);
	if (str[i] == '-')
	{
		negsign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * negsign);
}
