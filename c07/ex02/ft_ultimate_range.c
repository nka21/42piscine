/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 04:57:14 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/18 08:31:43 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

// int	main(void)
// {
// 	int	*arr;
// 	int	size;

// 	size = ft_ultimate_range(&arr, 2, 4);
// 	if (size == -1)
// 		printf("Error\n");
// 	else if (size == 0)
// 		printf("min >= max");
// 	else
// 	{
// 		printf("size: %d\n", size);
// 		for (int i = 0; i < size; i++)
// 			printf("%d ", arr[i]);
// 		printf("\n");
// 		free(arr);
// 	}
// 	return (0);
// }
