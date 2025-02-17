/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:22:49 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 21:26:45 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", ft_str_is_printable("42Tokyo"));
// 	printf("%d\n", ft_str_is_printable("\n"));
// 	return (0);
// }
