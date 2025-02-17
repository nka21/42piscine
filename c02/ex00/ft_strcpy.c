/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:49:11 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/10 22:57:19 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	src[] = "42Tokyo";
// 	char	dest[20];

// 	ft_strcpy(dest, src);
// 	write(1, dest, sizeof(src));
// 	return (0);
// }
