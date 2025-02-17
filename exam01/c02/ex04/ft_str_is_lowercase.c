#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char s[] = "42Tokyo";
	printf("%d\n", ft_str_is_lowercase(s));
	return (0);
}
