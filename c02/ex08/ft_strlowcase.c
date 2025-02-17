/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:40:18 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/10 23:05:59 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char	*result;

	result = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	c[] = "42Tokyo";
// 	write(1, ft_strlowcase(c), sizeof(c));
// 	return (0);
// }
