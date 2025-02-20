/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:53:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/20 15:33:21 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_print_comb(int arr[], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (arr[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_generate_comb(int arr[], int n, int index, int start)
{
	int	i;

	if (index == n)
	{
		ft_print_comb(arr, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		arr[index] = i;
		ft_generate_comb(arr, n, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (!(0 < n && n < 10))
		return ;
	ft_generate_comb(arr, n, 0, 0);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	ft_print_combn(atoi(argv[1]));
// 	return (0);
// }
