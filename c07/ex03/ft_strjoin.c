/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:48:09 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/22 20:04:22 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	ft_total_size(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	if (size == 0)
		return (1);
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	total++;
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_size;
	int		i;

	total_size = ft_total_size(size, strs, sep);
	result = (char *)malloc(sizeof(char) * total_size);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	int		size;
// 	char	*strs[] = {"Hello", "World!", "42Tokyo"};
// 	char	*sep;
// 	char	*result;

// 	size = 3;
// 	sep = ", ";
// 	result = ft_strjoin(size, strs, sep);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
