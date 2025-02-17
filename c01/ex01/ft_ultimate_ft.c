/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:11:34 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/08 22:59:03 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

// void	ft_putnbr(int n)
// {
// 	char	c;

// 	if (n >= 10)
// 		ft_putnbr(n / 10);
// 	c = (n % 10) + '0';
// 	write(1, &c, 1);
// }

// int	main(void)
// {
// 	int	n;
// 	int	*ptr1;
// 	int	**ptr2;
// 	int	***ptr3;
// 	int	****ptr4;
// 	int	*****ptr5;
// 	int	******ptr6;
// 	int	*******ptr7;
// 	int	********ptr8;
// 	int	*********ptr9;

// 	ptr1 = &n;
// 	ptr2 = &ptr1;
// 	ptr3 = &ptr2;
// 	ptr4 = &ptr3;
// 	ptr5 = &ptr4;
// 	ptr6 = &ptr5;
// 	ptr7 = &ptr6;
// 	ptr8 = &ptr7;
// 	ptr9 = &ptr8;
// 	ft_ultimate_ft(ptr9);
// 	ft_putnbr(n);
// 	return (0);
// }
