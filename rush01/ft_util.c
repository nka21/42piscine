/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:14:07 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 17:18:09 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puzzle.h"

/**
 * ft_rev_array - 配列を反転する
 * @arr: 反転させる4要素の配列
 */
void	ft_rev_arr(int *arr)
{
	int	left;
	int	right;
	int	tmp;

	left = 0;
	right = SIZE - 1;
	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

/**
 * ft_is_check - 視点の制約を満たしているか確認
 * @line: 4つの建物の高さが入った配列
 * @clue: 視点情報 (見える建物の数)
 * @reverse: 配列を逆順にするかどうか
 *
 * Return: 1 (条件を満たす), 0 (満たさない)
 */
int	ft_is_check(int *line, int clue, int reverse)
{
	int	tmp[SIZE];
	int	i;
	int	max;
	int	count;

	i = -1;
	while (++i < SIZE)
		tmp[i] = line[i];
	if (reverse)
		ft_rev_arr(tmp);
	max = 0;
	count = 0;
	i = 0;
	while (i < SIZE)
	{
		if (tmp[i] > max)
		{
			max = tmp[i];
			count++;
		}
		i++;
	}
	return (count == clue);
}
