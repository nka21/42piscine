/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:32:59 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/15 21:04:08 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	sqrt_recursive(int nb, long long i)
{
	if (i * i > nb)
		return (0);
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

// int	main(void)
// {
// 	printf("%d\n", ft_sqrt(2147395600));
// 	return (0);
// }
