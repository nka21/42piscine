/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:14:34 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 17:21:03 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puzzle.h"

/**
 * ft_init_grid - 盤面を 0 で初期化
 * @grid: 4x4 の盤面
 */
void	ft_init_grid(int grid[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

/**
 * ft_print_grid - 盤面を画面に出力
 * @grid: 4x4 の盤面
 */
void	ft_print_grid(int grid[SIZE][SIZE])
{
	int		i;
	int		j;
	char	num;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			num = grid[i][j] + '0';
			write(1, &num, 1);
			if (j < SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
