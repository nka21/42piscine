/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketomita <ketomita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:39:13 by ketomita          #+#    #+#             */
/*   Updated: 2025/02/23 23:37:09 by ketomita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "main.h"

char	*stra_key(int *k, char *buf)
{
	int 	t;
	int 	start;
	int 	finish;
	char	*kp;

	t = 0;
	start = *k;
	while (buf[*k] >= '0' && buf[*k] <= '9' || buf[*k] != ':')
		(*k)++;
	finish = *k;
	kp = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		kp[t++] = buf[start++];
	kp[t] = '\0';
	return (kp);
}

char	*stra_value(int *k, char *buf)
{
	int		t;
	int		start;
	int		finish;
	char	*kp2;

	t = 0;
	(*k)++;
	while (!(buf[*k] >= 33 && buf[*k] <= 126))
		(*k)++;
	start = *k;
	while (buf[*k] != '\n')
		(*k)++;
	finish = *k;
	kp2 = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		kp2[t++] = buf[start++];
	kp2[t] = '\0';
	return (kp2);
}

t_stract_dict	*read_file(void)
{
	t_stract_dict	*p;
	t_namae2		p2;

	p2.fd1 = 0;
	p2.byte_num = 1;
	p2.fd1 = open("./numbers.dict", O_RDONLY);
	if (p2.fd1 == -1)
		return (NULL);
	p2.i = 0;
	p2.buf = malloc(count_size() * sizeof(char));
	while (p2.i < count_size() - 1 && (p2.byte_num > 0))
	{
		if (p2.buf[p2.i] == EOF)
			break ;
			p2.byte_num = read(p2.fd1, &p2.buf[p2.i], 1);
		p2.i++;
	}
	p2.buf[p2.i] = '\0';
	p = (t_stract_dict *)malloc(count_row(p2.buf) * sizeof(t_stract_dict));
	p2.k = 0;
	p2.n = 0;
	while (p2.k < p2.i)
	{
		p[p2.n].key = ft_atoi(stra_key(&p2.k, p2.buf));
		p[p2.n++].value = ft_strdup(stra_value(&p2.k, p2.buf));
	}
	if (p2.byte_num == -1)
		return (NULL);
	close(p2.fd1);
	return (p);
}


int	ft_read(unsigned int num)
{
	char			**convert_str_result;
	int				result_size;
	int				i;

	convert_str_result = convert_to_words(read_file(), num, &result_size);
	i = 0;
	while (i < result_size)
	{
		("%s ", convert_str_result[i]);
		i++;
	}
	write(1, "\n", 1);
	free(convert_str_result);
	return (0);
}
