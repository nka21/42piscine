/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:21:12 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/08 19:51:43 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	ans;

	ans = 'z';
	while (ans >= 'a')
	{
		write(1, &ans, 1);
		ans--;
	}
}

// review
// int main(void)
// {
// 	ft_print_reverse_alphabet();
// 	return (0);
// }
