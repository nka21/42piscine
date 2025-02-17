/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:11:22 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/09 22:45:03 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		ft_atoi(char *str);
int		check_error(char **argv);

void	draw_line(int x, char corner, char horizontal)
{
	int		row;
	char	c;

	row = 0;
	while (row < x)
	{
		if (row == 0 || row == x - 1)
			c = corner;
		else
			c = horizontal;
		write(1, &c, 1);
		row++;
	}
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	char	corner;
	char	horizontal;
	char	vertical;
	char	space;
	int		column;

	corner = 'o';
	horizontal = '-';
	vertical = '|';
	space = ' ';
	column = 0;
	while (column < y)
	{
		if (column == 0 || column == y - 1)
		{
			draw_line(x, corner, horizontal);
		}
		else
		{
			draw_line(x, vertical, space);
		}
		column++;
	}
}

int	validate_positive_integer(char *str)
{
	if (*str == '-' || *str == '0')
	{
		write(1, "0より大きい数を入力してください。\n", 51);
		return (0);
	}
	return (1);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			write(1, "数字以外が入力されています。数値を入力してください\n", 77);
			return (0);
		}
		str++;
	}
	return (1);
}
