/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:38:35 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/15 21:04:13 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	s;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	s = ft_recursive_power(nb, power - 1);
	return (nb * s);
}

// int	main(void)
// {
// 	printf("%d\n", ft_recursive_power(0, -1));
// 	return (0);
// }
