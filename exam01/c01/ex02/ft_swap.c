#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 3;
	ft_swap(&a, &b);
	a += '0';
	b += '0';
	write(1, &a, 1);
	write(1, &b, 1);
	return (0);
}
