
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		while (size > 0)
			str[size--] = '\0';
		str[0] = '\0';
	}
	else
		return (0);
	return (str);
}
