/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:29:55 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 20:15:25 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	sqrt_recursive(int nb, long long i)
{
	if (i * i > nb)
		return (i - 1);
	if (i * i == nb)
		return (i);
	return (sqrt_recursive(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return (sqrt_recursive(nb, 1));
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt_nb;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	sqrt_nb = ft_sqrt(nb);
	while (i <= sqrt_nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

// int main(void)
// {
// 	int a = 0;
// 	scanf("%d", &a);
// 	printf("%d\n", ft_is_prime(a));
// 	return (0);
// }
