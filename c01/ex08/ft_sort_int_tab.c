/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:12:45 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/09 12:16:22 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

// int	main(void)
// {
// 	int		tab[] = {3, 4, 1, 2, 5};
// 	int		i;
// 	int		size;
// 	char	c;

// 	i = 0;
// 	size = 5;
// 	ft_sort_int_tab(tab, size);
// 	while (i < size)
// 	{
// 		c = tab[i] + '0';
// 		write(1, &c, 1);
// 		i++;
// 	}
// 	return (0);
// }
