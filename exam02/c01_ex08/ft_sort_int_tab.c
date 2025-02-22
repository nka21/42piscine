#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}

int main(void)
{
	int tab[] = {5, 4, 3, 2, 1};
	int size = sizeof(tab) / sizeof(tab[0]);
	ft_sort_int_tab(tab, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}
	return (0);
}
