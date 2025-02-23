/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 03:48:23 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/24 05:16:46 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * ft_nbr_len - 数値を特定の基数で表すときの桁数を計算
 * @nbr: 変換対象の整数
 * @base_len: 使用する基数の長さ
 *
 * Return: 数値を表現するのに必要な文字数
 */
int	ft_nbr_len(int nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

/**
 * get_base_value - 指定された文字が基数の中で何番目かを取得する
 * @c: 探索対象の文字
 * @base: 探索する基数の文字列
 *
 * Return: 文字のインデックス（見つからなければ -1）
 */
int	get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * ft_atoi_base - 文字列を整数に変換する（指定された基数を使用）
 * @str: 変換対象の文字列
 * @base: 変換に使用する基数
 *
 * Return: 変換された整数
 */
int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;

	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (get_base_value(*str, base) != -1)
	{
		result = result * base_len + get_base_value(*str, base);
		str++;
	}
	return (result * sign);
}

/**
 * ft_putnbr_base - 整数を指定された基数の文字列に変換する
 * @nbr: 変換する整数
 * @base: 変換後の基数
 *
 * Return: 変換された文字列（malloc() で確保されるので free() が必要）
 */
char	*ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		base_len;
	char	*result;
	long	num;

	base_len = ft_strlen(base);
	num = nbr;
	len = ft_nbr_len(nbr, base_len);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	if (num == 0)
		result[0] = base[0];
	while (num)
	{
		result[--len] = base[num % base_len];
		num /= base_len;
	}
	return (result);
}
