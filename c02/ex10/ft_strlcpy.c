/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:50 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 13:36:29 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*ptr_start;
	char			*dest_end;
	unsigned int	len;

	ptr_start = src;
	dest_end = dest + size - 1;
	while (*src != '\0')
		src++;
	len = src - ptr_start;
	src = ptr_start;
	while (dest < dest_end && *src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (len);
}

// int main(void)
// {
// 	char dest[10];
// 	char *src = "Hello, World!";

//     unsigned int copied = ft_strlcpy(dest, src, sizeof(dest));
//     printf("コピー後の文字列: %s\n", dest);
//     printf("コピーした文字列の長さ: %d\n", copied);
// 	return (0);
// }
