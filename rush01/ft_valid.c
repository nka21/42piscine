/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:12:33 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 17:58:20 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puzzle.h"

/**
 * ft_pos_valid - 指定したマスに高さを置けるか判定
 * @grid: 4x4 の盤面
 * @row: 行インデックス
 * @col: 列インデックス
 * @height: 置きたい建物の高さ
 * @clues: 視点情報
 *
 * Return: 1 (置ける), 0 (置けない)
 */
int	ft_pos_valid(int grid[SIZE][SIZE], int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (i != col && (grid[row][i] == height))
			return (0);
		if (i != row && (grid[i][col] == height))
			return (0);
		i++;
	}
	return (1);
}

/**
 * ft_col_valid - 列全体が正しい並びになっているか判定
 * @grid: 4x4 の盤面
 * @clues: 視点情報
 * @row: 行インデックス
 * @col: 列インデックス
 *
 * Return: 1 (合致してる), 0 (合致していない)
 */
int	ft_col_valid(int grid[SIZE][SIZE], int *clues, int col)
{
	int	i;
	int	col_arr[SIZE];

	i = 0;
	while (i < SIZE)
	{
		col_arr[i] = grid[i][col];
		i++;
	}
	if (!ft_is_check(col_arr, clues[col], 0))
		return (0);
	if (!ft_is_check(col_arr, clues[SIZE + col], 1))
		return (0);
	return (1);
}

/**
 * ft_row_valid - 行全体が正しい並びになっているか判定
 * @grid: 4x4 の盤面
 * @clues: 視点情報
 * @row: 行インデックス
 * @col: 列インデックス
 *
 * Return: 1 (合致してる), 0 (合致していない)
 */
int	ft_row_valid(int grid[SIZE][SIZE], int *clues, int row)
{
	int	i;
	int	row_arr[SIZE];

	i = 0;
	while (i < SIZE)
	{
		row_arr[i] = grid[row][i];
		i++;
	}
	if (!ft_is_check(row_arr, clues[2 * SIZE + row], 0))
		return (0);
	if (!ft_is_check(row_arr, clues[3 * SIZE + row], 1))
		return (0);
	return (1);
}

/**
 * ft_fin_check - 行または列全体が入力の情報条件を満たしているか判定
 * @grid: 4x4 の盤面
 * @clues: 視点情報
 * @row: 行インデックス
 * @col: 列インデックス
 *
 * Return: 1 (満たしてる), 0 (満たしていない)
 */
int	ft_fin_check(int grid[SIZE][SIZE], int *clues, int row, int col)
{
	if (col == SIZE - 1)
	{
		if (!ft_row_valid(grid, clues, row))
			return (0);
	}
	if (row == SIZE - 1)
	{
		if (!ft_col_valid(grid, clues, col))
			return (0);
	}
	return (1);
}
