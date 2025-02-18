/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:08:26 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/18 04:57:58 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlen(char *src)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char			*dest;
	char			*start_ptr;
	unsigned int	len;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	start_ptr = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start_ptr);
}

// int main(void)
// {
// 	char *src = "42Tokyo";
// 	char *dest = ft_strdup(src);

// 	if (!dest)
// 		printf("Error\n");
// 	else
// 	{
// 		printf("src: %s\n", src);
// 		printf("dest:  %s\n", dest);
// 		free(dest);
// 	}
// 	return (0);
// }
