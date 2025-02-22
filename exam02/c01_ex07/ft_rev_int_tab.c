#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int tmp;
	int start = 0;
	int end = size - 1;
	while (start < end)
	{
		tmp = tab[start];
		tab[start] = tab[end];
		tab[end] = tmp;

		start++;
		end--;
	}
}

int	main(void)
{
	int	size;
	int	tab[] = {1, 2, 3, 4, 5};
	int	i;
	char c;

	size = 5;
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	return (0);
}
