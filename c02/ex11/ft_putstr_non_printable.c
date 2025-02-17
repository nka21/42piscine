/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:34:57 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/18 04:26:21 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex(unsigned char str)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[str / 16]);
	ft_putchar(hex[str % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
		{
			ft_putchar(*str);
		}
		else
		{
			ft_putchar('\\');
			ft_hex((unsigned char)*str);
		}
		str++;
	}
}

// int	main(void)
// {
// 	char str[] = "Coucou\ntu vas bien ?";
// 	ft_putstr_non_printable(str);
// 	return (0);
// }
