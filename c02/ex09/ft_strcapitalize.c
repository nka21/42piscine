/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:25:14 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 13:36:06 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_numeric(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

int	is_lowercase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		return (1);
	return (0);
}

int	is_uppercase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*result;
	int		in_word;

	result = str;
	in_word = 1;
	while (*str != '\0')
	{
		if (is_numeric(str) || is_lowercase(str) || is_uppercase(str))
		{
			if (in_word && is_lowercase(str))
				*str -= 32;
			else if (!in_word && is_uppercase(str))
				*str += 32;
			in_word = 0;
		}
		else
		{
			in_word = 1;
		}
		str++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	str[] = "";

// 	printf("変換前文字列: %s\n", str);
// 	printf("変換後文字列: %s\n", ft_strcapitalize(str));
// 	return (0);
// }
