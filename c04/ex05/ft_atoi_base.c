/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:54:37 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/22 10:42:35 by nkojima          ###   ########.fr       */
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

int	ft_is_space(char c)
{
	return (c > 0 && c <= 32);
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
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
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

/**
 * その文字が、baseの中にあるのかどうか
 * あるならbase[i] ないなら-1
 */
int	get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	s;
	int	result;
	int	base_len;

	result = 0;
	s = 1;
	if (!is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	while (ft_is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -s;
		str++;
	}
	while (*str)
	{
		if (get_base_value(*str, base) == -1)
			break ;
		result = result * base_len + get_base_value(*str, base);
		str++;
	}
	return (result * s);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("101", "01"));                 // 5 (2進数)
// 	printf("%d\n", ft_atoi_base("7F", "0123456789ABCDEF"));    // 127 (16進数)
// 	printf("%d\n", ft_atoi_base("-42", "0123456789"));         // -42 (10進数)
// 	printf("%d\n", ft_atoi_base("  -101", "01"));              // -5 (2進数)
// 	printf("%d\n", ft_atoi_base("  +1A", "0123456789ABCDEF")); // 26 (16進数)
// 	printf("%d\n", ft_atoi_base("ZZ", "0123456789ABCDEF"));    // 0 (無効)
// 	printf("%d\n", ft_atoi_base("12", "1"));                   // 0 (無効)
// 	printf("%d\n", ft_atoi_base("12", ""));                    // 0 (無効)
// 	return (0);
// }
