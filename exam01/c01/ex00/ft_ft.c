#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	nbr;

	nbr = 0;
	ft_ft(&nbr);
	printf("%d\n", nbr);
	return (0);
}
