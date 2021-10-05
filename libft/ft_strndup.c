
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;
	char	*b;

	new = (char *)malloc(sizeof(char) * (n + 1));
	b = new;
	if (new)
	{
		while (*s1 && n--)
			*new++ = *s1++;
		*new = '\0';
	}
	return (b);
}
