/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:45:55 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/18 04:27:14 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cnt;

	cnt = 0;
	while (*s1 != '\0' && cnt < n && (*s1 == *s2))
	{
		s1++;
		s2++;
		cnt++;
	}
	if (cnt == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main(void)
// {
// 	unsigned int	n;
// 	char			*s1;
// 	char			*s2;

// 	n = 3;
// 	s1 = "42Tokyo";
// 	s2 = "42T0kyo";
// 	printf("%d\n", ft_strncmp(s1, s2, n));
// 	return (0);
// }
