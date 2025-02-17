#include <stdio.h>

int ft_str_is_printable(char *str)
{
	while(*str)
	{
		if (!(*str >= 32 && *str <= 126))
			return(0);
		str++;
	}
	return (1);
}

int main(void)
{
	char s[] = "42Tokyo";
	printf("%d\n", ft_str_is_printable(s));
	return (0);
}
