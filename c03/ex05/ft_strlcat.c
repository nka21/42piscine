/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:50:53 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/12 22:13:43 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len = ft_strlen(dest);
	unsigned int src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	while (*dest < size - 1 && *src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}
