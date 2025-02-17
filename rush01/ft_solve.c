/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:12:01 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 17:22:22 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puzzle.h"

/**
 * ft_solve - バックトラッキングで解を探索
 * @grid: 4x4 の盤面
 * @pos: 現在のマスの位置 (0-15)
 * @clues: 視点情報
 *
 * Return: 1 (成功), 0 (失敗)
 */
int	ft_solve(int grid[SIZE][SIZE], int *clues, int pos)
{
	int	i;
	int	j;
	int	height;

	if (pos == SIZE * SIZE)
		return (1);
	i = pos / SIZE;
	j = pos % SIZE;
	height = 1;
	while (height <= SIZE)
	{
		if (ft_pos_valid(grid, i, j, height))
		{
			grid[i][j] = height;
			if (ft_fin_check(grid, clues, i, j) && ft_solve(grid, clues,
					pos + 1))
				return (1);
			grid[i][j] = 0;
		}
		height++;
	}
	return (0);
}
