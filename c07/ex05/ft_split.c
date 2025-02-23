/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 05:26:35 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/24 06:07:48 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * is_charset - 指定された文字が区切り文字かを判定する
 * @c: 判定する文字
 * @charset: 区切り文字の集合
 *
 * Return: c が charset に含まれていれば 1、それ以外は 0
 */
int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/**
 * word_count - 文字列 str を区切り文字で分割したときの単語の個数をカウントする
 * @str: 入力文字列
 * @charset: 区切り文字の集合
 *
 * Return: 単語の個数
 */
int	word_count(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_charset(*str, charset) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_charset(*str, charset))
			in_word = 0;
		str++;
	}
	return (count);
}

/**
 * word_dup - 指定された範囲の文字列を新しいメモリ領域にコピーする
 * @start: コピー元の文字列の開始アドレス
 * @len: コピーする文字数
 *
 * Return: コピーされた新しい文字列（malloc で確保）
 */
char	*word_dup(char *start, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * ft_split - 文字列 str を指定された区切り文字で分割し、各単語を配列として返す
 * @str: 入力文字列
 * @charset: 区切り文字の集合
 *
 * Return: 分割された文字列の配列（NULL 終端）。失敗時は NULL を返す。
 */
char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**result;
	int		total_len;
	char	*start;

	i = 0;
	total_len = word_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			start = str;
			while (*str && !is_charset(*str, charset))
				str++;
			result[i++] = word_dup(start, str - start);
		}
		str++;
	}
	result[i] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split("hello,world!this,is a 42tokyo.", ",! ");
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("word[%d] %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
