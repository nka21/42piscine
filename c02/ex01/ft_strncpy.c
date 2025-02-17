/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:40:56 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 13:38:19 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*result;
	int		i;

	result = dest;
	i = 0;
	while (i < n && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	// srcの長さがn以上なら'\0'をつけない
// 	unsigned int n = 10;
// 	char src[] = "42Tokyo";
// 	char dest[10];
// 	ft_strncpy(dest, src, n);
// 	printf("%s\n", dest);
// 	return (0);
// }
