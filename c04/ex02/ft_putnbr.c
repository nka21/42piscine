/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:26:43 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/14 20:31:33 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		i;
	char	buf[12];

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		nb = -nb;
	}
	i = 0;
	while (nb || !i)
	{
		buf[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	while (i)
	{
		i--;
		write(1, &buf[i], 1);
	}
}

// int	main(void)
// {
// 	int	d;

// 	d = 42;
// 	ft_putnbr(d);
// 	return (0);
// }
