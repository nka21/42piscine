#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*ptr_start;
	unsigned int	i;

	ptr_start = dest;
	i = 0;
	while (i < n && *src)
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest++ = '\0';
		i++;
	}
	return (ptr_start);
}

int	main(void)
{
	char	dest[3];
	char	src[] = "42Tokyo";

	printf("%s\n", ft_strncpy(dest, src, sizeof(dest)));
	return (0);
}
