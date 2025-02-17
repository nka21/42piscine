/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:08:20 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 17:20:52 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puzzle.h"

/**
 * ft_parse_input - コマンドライン引数を解析し、視点情報を取得
 * @str: スペース区切りの視点情報の文字列
 *
 * Return: 視点情報を格納した動的配列 (成功), NULL (エラー)
 */
int	*ft_parse_input(char *str)
{
	int	*clues;
	int	i;

	clues = malloc(sizeof(int) * SIZE * SIZE);
	if (!clues)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			str++;
		if (!(str[i] >= '1' && str[i] <= ('0' + SIZE)))
		{
			free(clues);
			return (NULL);
		}
		if (str[i] >= '1' && str[i] <= ('0' + SIZE))
			clues[i] = str[i] - '0';
		i++;
	}
	return (clues);
}
