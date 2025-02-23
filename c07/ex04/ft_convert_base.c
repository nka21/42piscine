/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 03:15:01 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/24 05:25:52 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);
char	*ft_putnbr_base(int nbr, char *base);

/**
 * is_valid_base - 基数が有効かどうかをチェックする
 * @base: 検証する基数の文字列
 *
 * Return: 有効なら 1, 無効なら 0
 */
int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (9 <= base[i] && base[i] <= 13)
			|| base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * ft_convert_base - 数値文字列を異なる基数に変換する
 * @nbr: 変換対象の文字列
 * @base_from: 現在の基数
 * @base_to: 変換後の基数
 *
 * Return: 変換後の文字列（ヒープ上に確保されるため、使用後に free() 必須）
 *         基数が無効な場合は NULL を返す。
 */
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		numeric;
	char	*result;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	numeric = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(numeric, base_to);
	return (result);
}

// int	main(void)
// {
// 	char	*nbr;
// 	char	*base_from;
// 	char	*base_to;
// 	char	*result;

// 	nbr = "   12";
// 	base_from = "0123456789";
// 	base_to = "0123456789ABCDEF";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
