/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:34:44 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 21:42:57 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*find_start;
	char	*search;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		find_start = str;
		search = to_find;
		while (*str && *search && (*str == *search))
		{
			str++;
			search++;
		}
		if (*search == '\0')
			return (find_start);
		str = find_start + 1;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "42Tokyo";
// 	char to_find[] = "Tok";
// 	printf("%s\n", ft_strstr(str, to_find));
// 	return (0);
// }
