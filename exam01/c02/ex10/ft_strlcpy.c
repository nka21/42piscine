#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char *ptr_start = src;
	char *dest_end = dest + size - 1;
	while (*src)
		src++;
	unsigned int len = src - ptr_start;
	src = ptr_start;
	while (*dest < *dest_end && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (len);
}

int main(void)
{
	char dest[20];
	char src[] = "42Tokyo";
	unsigned int size = 5;
	printf("%d\n", ft_strlcpy(dest, src, size));
	return (0);
}
