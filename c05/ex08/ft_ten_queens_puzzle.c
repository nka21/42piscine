/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:36:36 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/25 09:26:30 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * is_safe - クイーンを (row, col) に配置できるか判定する
 * @board: すでに配置されたクイーンの位置を格納した配列
 * @col: 配置しようとしている列
 * @row: 配置しようとしている行
 * Return: 配置可能なら 1、配置できないなら 0 を返す
 */
int	is_safe(int board[], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col || board[i] + i == row
			+ col)
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_solve - クイーンを配置した盤面を出力する
 * @board: クイーンの配置を格納した配列
 */
void	print_solve(int board[])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

/**
 * solve - 10クイーンパズルを再帰的に解く
 * @board: クイーンの配置を格納する配列
 * @col: 現在配置を試みている列
 * Return: 発見した解の総数
 */
int	solve(int board[], int col)
{
	int	count;
	int	row;

	if (col == 10)
	{
		print_solve(board);
		return (1);
	}
	count = 0;
	row = 0;
	while (row < SIZE)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			count += solve(board, col + 1);
		}
		row++;
	}
	return (count);
}

/**
 * ft_ten_queens_puzzle - 10クイーンパズルを解く
 * Return: 解の総数
 */
int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE];

	return (solve(board, 0));
}

// int	main(void)
// {
// 	ft_ten_queens_puzzle();
// 	return (0);
// }
