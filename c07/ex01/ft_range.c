/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:35:28 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/22 18:44:18 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	i;
	int	*arr;

	if (min >= max)
		return (NULL);
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*result;

// 	min = 2;
// 	max = 4;
// 	result = ft_range(min, max);
// 	for (int i = 0; i < max - min; i++)
// 	{
// 		printf("%d\n", result[i]);
// 	}
//  free(result);
// 	return (0);
// }
