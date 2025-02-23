/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iroiro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketomita <ketomita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:10:13 by ketomita          #+#    #+#             */
/*   Updated: 2025/02/23 23:15:48 by ketomita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

long long	ft_atoi(char *str)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || \
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

int	count_size(void)
{
	int		i;
	int		fd;
	char	buf[1];

	i = 0;
	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buf, 1) > 0)
		i++;
	close(fd);
	return (i);
}

int	count_row(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		count++;
		i++;
	}
	return (count);
}

int	check_length(char *av)
{
	int	length;

	if (!av)
		return (0);
	length = 0;
	while (av[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(char *av)
{
	int		i;
	char	*p;

	i = 0;
	if (!av)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (check_length(av) + 1));
	if (!p)
		return (NULL);
	while (av[i])
	{
		p[i] = av[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
