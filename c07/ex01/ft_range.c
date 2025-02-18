/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:00:15 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/18 07:41:39 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ranges;

	if (min >= max)
		return (NULL);
	ranges = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < (max - min))
	{
		ranges[i] = min + i;
		i++;
	}
	return (ranges);
}

// int main(int argc, char *argv[])
// {
// 	(void) argc;
// 	int min = atoi(argv[1]);
// 	int max = atoi(argv[2]);
// 	int *tmp = ft_range(min, max);
// 	for (int i = 0; i < max - min; i++)
// 		printf("%d ", tmp[i]);
// 	return (0);
// }
