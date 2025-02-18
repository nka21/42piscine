/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:34:57 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/18 09:17:40 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

int	ft_total_len(int size, char **strs, char *sep)
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

char	*ft_strcat(char *dest, char *src)
{
	char	*start_ptr;

	start_ptr = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start_ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_size;
	int		i;

	total_size = ft_total_len(size, strs, sep);
	result = (char *)malloc(total_size);
	if (!result)
		return (NULL);
	result[0] = '\0';
	if (size == 0)
		return (result);
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
// 	char	*strs[] = {"Hello", "42", "Tokyo"};
// 	char	*sep;
// 	char	*ans;

// 	sep = ", ";
// 	ans = ft_strjoin(3, strs, sep);
// 	if (!ans)
// 		printf("NULL\n");
// 	else
// 		printf("ans: %s\n", ans);
// 	free(ans);
// 	return (0);
// }
