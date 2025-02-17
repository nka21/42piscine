/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:25:17 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/10 13:35:06 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		rush(int x, int y);
int			validate_positive_integer(const char *str);
int			is_number(const char *str);

long long	ft_atoi(char *str)
{
	int			i;
	long long	result;
	long long	prev_result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev_result = result;
		result = result * 10 + (str[i] - '0');
		if (result < prev_result || result > 2147483647)
			return (-1);
		i++;
	}
	return (result);
}

int	is_valid_length(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		length++;
		str++;
	}
	return (length <= 10);
}

int	check_error(char **argv)
{
	char	*inputs[2];
	int		i;

	inputs[0] = argv[1];
	inputs[1] = argv[2];
	i = 0;
	while (i < 2)
	{
		if (!validate_positive_integer(inputs[i]) || !is_number(inputs[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			max_int;
	long long	num1;
	long long	num2;

	max_int = 2147483647;
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[2]);
	if (argc != 3)
	{
		write(1, "引数を設定してください \n", 36);
		return (1);
	}
	if (!check_error(argv))
	{
		return (1);
	}
	if (!is_valid_length(argv[1]) || !is_valid_length(argv[2]) || num1 == -1
		|| num2 == -1 || num1 > max_int || num2 > max_int)
	{
		write(1, "オーバーフローです。\n", 32);
		return (1);
	}
	rush(num1, num2);
	return (0);
}
