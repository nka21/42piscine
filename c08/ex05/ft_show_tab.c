/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:09:26 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/26 08:43:12 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

// void	free_stock_str(t_stock_str *stock)
// {
// 	int	i;

// 	i = 0;
// 	while (stock[i].str)
// 	{
// 		free(stock[i].copy);
// 		i++;
// 	}
// 	free(stock);
// }

// int	main(void)
// {
// 	char		*av[] = {"hello", "world", "42tokyo"};
// 	t_stock_str	*result;

// 	result = ft_strs_to_tab(3, av);
// 	if (!result)
// 	{
// 		printf("Memory failed\n");
// 		return (1);
// 	}
// 	ft_show_tab(result);
// 	free_stock_str(result);
// 	return (0);
// }
