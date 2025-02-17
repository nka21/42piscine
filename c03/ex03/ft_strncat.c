/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:54:13 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 20:31:57 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*result;

	result = dest;
	while (*dest)
		dest++;
	while (nb-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (result);
}

// int	main(void)
// {
// 	char dest[20] = "42";
// 	char src[] = "Tokyo";
// 	printf("%s\n", ft_strncat(dest, src, 3));
// 	return (0);
// }
