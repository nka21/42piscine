/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:58:43 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/08 19:50:55 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	ans;

	ans = 'a';
	while (ans <= 'z')
	{
		write(1, &ans, 1);
		ans++;
	}
}

// review
// int	main(void)
// {
// 	ft_print_alphabet();
// 	return (0);
// }
