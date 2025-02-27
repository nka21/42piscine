/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:52:27 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/26 19:25:33 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* 文字が区切り文字か判定 */
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

/* 文字列の単語数を数える */
int	word_count(char *str, char *charset)
{
	int	cnt;
	int	in_word;

	cnt = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_charset(*str, charset) && in_word == 0)
		{
			in_word = 1;
			cnt++;
		}
		else if (is_charset(*str, charset))
			in_word = 0;
		str++;
	}
	return (cnt);
}

/* 指定された長さの単語をコピー */
char	*word_dup(char *str, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/* 文字列を区切り文字で分割 */
char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		len_total;
	char	*start;
	int		i;

	len_total = word_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (len_total + 1));
	if (!result)
		return (NULL);
	i = 0;
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

// /* 分割結果を解放 */
// void	free_split(char **result)
// {
// 	int	i;

// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("word[%d]: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	char	**result;

// 	result = ft_split("hello,world!this,is a 42tokyo.", ",! ");
// 	free_split(result);
// 	return (0);
// }
