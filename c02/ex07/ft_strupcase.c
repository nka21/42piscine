/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:11:24 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/10 22:52:24 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	char	*result;

	result = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (result);
}

// int	main(void)
// {
// 	char str[] = "42Tokyo";
// 	write(1, ft_strupcase(str), sizeof(str));
// 	return (0);
// }
