#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr_start;

	ptr_start = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr_start);
}

int	main(void)
{
	char	dest[20];
	char	src[] = "42Tokyo";

	printf("%s\n", ft_strcpy(dest, src));
	return (0);
}
