/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:56:22 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 14:29:48 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main(void)
// {
// 	char	s2[] = "Hello";

// 	printf("===== strcmp デバッグテスト =====\n");
// 	// 1. 同じ文字列（等しい）
// 	printf("Test 1: \"abc\" vs \"abc\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("abc", "abc"));
// 	// 2. 途中で違う文字（辞書順で小さい）
// 	printf("Test 2: \"abc\" vs \"abd\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("abc", "abd"));
// 	// 3. 途中で違う文字（辞書順で大きい）
// 	printf("Test 3: \"abd\" vs \"abc\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("abd", "abc"));
// 	// 4. s1 が短い
// 	printf("Test 4: \"abc\" vs \"abcd\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("abc", "abcd"));
// 	// 5. s2 が短い
// 	printf("Test 5: \"abcd\" vs \"abc\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("abcd", "abc"));
// 	// 6. 空文字列との比較
// 	printf("Test 6: \"\" vs \"abc\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("", "abc"));
// 	printf("Test 7: \"abc\" vs \"\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("abc", ""));
// 	printf("Test 8: \"\" vs \"\"\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
// 	// 7. 特殊文字（非ASCII）
// 	printf("Test 9: \"Hello\\200\" vs \"Hello\"\n");
// 	char s1[] = "Hello\200"; // 200は非ASCII
// 	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
// 	return (0);
// }
