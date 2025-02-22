/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:57:21 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/22 09:51:23 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_nbr_recursive(long num, char *base, int base_len)
{
	char	c;

	if (num >= base_len)
		print_nbr_recursive(num / base_len, base, base_len);
	c = base[num % base_len];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	num;

	num = nbr;
	base_len = ft_strlen(base);
	if (!is_valid_base(base))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	print_nbr_recursive(num, base, base_len);
}

// int	main(void)
// {
// 	ft_putnbr_base(42, "0123456789"); // → "42"
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "0123456789ABCDEF"); // → "-2A"
// 	write(1, "\n", 1);
// 	ft_putnbr_base(255, "01"); // → "11111111"
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-255, "poneyvif"); // → "-iff"
// 	write(1, "\n", 1);
// 	ft_putnbr_base(0, "0123456789"); // → "0"
// 	write(1, "\n", 1);
// 	ft_putnbr_base(100, "01+2"); // → (何も出力しない)
// 	write(1, "\n", 1);
// 	ft_putnbr_base(100, "0"); // → (何も出力しない)
// 	return (0);
// }
