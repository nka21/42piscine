#include <stdio.h>

int	ft_strlen(char *str)
{
	char	*ptr_start;

	ptr_start = str;
	while (*str)
		str++;
	return (str - ptr_start);
}

int	main(void)
{
	printf("%d\n", ft_strlen("42Tokyo"));
	return (0);
}
