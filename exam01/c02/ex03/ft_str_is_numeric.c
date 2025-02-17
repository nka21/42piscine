#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char	s[] = "42Tokyo";

	printf("%d\n", ft_str_is_numeric(s));
	return (0);
}
