#include "libft.h"

/* bzero - replaces all n bytes of a string with '\0' */
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}
