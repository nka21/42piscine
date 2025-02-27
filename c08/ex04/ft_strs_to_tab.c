/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:57:33 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/26 08:43:32 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len_src;
	char	*dup;
	int		i;

	len_src = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len_src)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		if (!arr[i].copy)
		{
			while (--i >= 0)
				free(arr[i].copy);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }

// void	ft_putnbr(int nb)
// {
// 	char	c;

// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		if (nb == -2147483648)
// 			write(1, "2147483648", 10);
// 		nb = -nb;
// 	}
// 	if (nb >= 10)
// 		ft_putnbr(nb / 10);
// 	c = (nb % 10) + '0';
// 	write(1, &c, 1);
// }

// void	ft_show_tab(struct s_stock_str *par)
// {
// 	int	i;

// 	i = 0;
// 	while (par[i].str)
// 	{
// 		ft_putstr(par[i].str);
// 		write(1, "\n", 1);
// 		ft_putnbr(par[i].size);
// 		write(1, "\n", 1);
// 		ft_putstr(par[i].copy);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }

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
