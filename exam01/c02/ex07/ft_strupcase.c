#include <stdio.h>

int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char *ft_strupcase(char *str)
{
	char *ptr_start = str;
	while(*str)
	{
		if (is_lower(*str))
			*str -= 32;
		str++;
	}
	return(ptr_start);
}

int	main(void)
{
	char s[] = "42Tokyo";
	printf("%s\n", ft_strupcase(s));
	return (0);
}
