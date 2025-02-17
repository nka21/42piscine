#include <stdio.h>

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char *ft_strlowcase(char *str)
{
	char *ptr_start = str;
	while(*str)
	{
		if (is_upper(*str))
			*str += 32;
		str++;
	}
	return(ptr_start);
}

int main(void)
{
	char s[] = "42Tokyo";
	printf("%s\n", ft_strlowcase(s));
	return (0);
}
