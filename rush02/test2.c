/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketomita <ketomita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:38:29 by hhangai           #+#    #+#             */
/*   Updated: 2025/02/23 23:02:47 by ketomita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char	*search_dict(int q, t_stract_dict *dict)
{
	int	n;

	n = 0;
	while (dict[n].key != q)
		n++;
	return (dict[n].value);
}

char	**insert_three_digits(t_stract_dict *dict, int remainder, \
	int *result_size)
{
	int		tmp;
	int		i;
	int		result_idx;
	char	**result;

	result_idx = 0;
	i = 0;
	result = malloc(5 * sizeof(char *));
	if (!result)
		return (NULL);
	if (remainder / 100 != 0)
	{
		tmp = remainder / 100;
		result[result_idx++] = dict[tmp].value;
		result[result_idx++] = search_dict(100, dict);
		remainder %= 100;
	}
	if (remainder > 20)
	{
		tmp = remainder / 10 * 10;
		result[result_idx++] = search_dict(tmp, dict);
		remainder %= 10;
	}
	else if (remainder >= 10)
		result[result_idx++] = search_dict(remainder, dict);
	if (remainder > 0)
		result[result_idx++] = search_dict(remainder, dict);
	*result_size = result_idx;
	return (result);
}
void	ft_units(long long *units)
{
	units[0] = 1000000000;
	units[1] = 1000000;
	units[2] = 1000;
	units[3] = 100;
}
char	**convert_to_words(t_stract_dict *dict, long long number, \
	int *result_size)
{
	t_namae			p;
	long long		*units;

	ft_units(units);
	p.idx = 0;
	p.i = 0;
	p.final_result = malloc(100 * sizeof(char *));
	if (!p.final_result)
		return (NULL);
	while (p.i < 4)
	{
		p.unit = units[p.i];
		p.remainder = number / p.unit;
		number %= p.unit;
		if (p.remainder > 0)
		{
			p.section_result = insert_three_digits(dict, p.remainder,
					&p.result_size_for_section);
			p.j = 0;
			while (p.j < p.result_size_for_section)
			{
				p.final_result[p.idx++] = p.section_result[p.j++];
			}
			if (p.i == 0)
				p.final_result[p.idx++] = search_dict(units[p.i], dict);
			else if (p.i == 1)
				p.final_result[p.idx++] = search_dict(units[p.i], dict);
			else if (p.i == 2)
				p.final_result[p.idx++] = search_dict(units[p.i], dict);
			else if (p.i == 3)
				p.final_result[p.idx++] = search_dict(units[p.i], dict);
		}
		p.i++;
	}
	if (number > 20)
	{
		p.temp = number / 10 * 10;
		number %= 10;
		p.final_result[p.idx++] = search_dict(p.temp, dict);
		p.final_result[p.idx++] = search_dict(number, dict);
	}
	else
		p.final_result[p.idx++] = search_dict(number, dict);
	*result_size = p.idx;
	return (p.final_result);
}
