/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketomita <ketomita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:07:03 by ketomita          #+#    #+#             */
/*   Updated: 2025/02/23 23:02:49 by ketomita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct key_value {
	int			key;
	char		*value;
}	t_stract_dict;

typedef struct namae {
	int			idx;
	int			i;
	long long	unit;
	long long	remainder;
	int			result_size_for_section;
	int			j;
	int			temp;
	char		**section_result;
	char		**final_result;
}	t_namae;

char	**insert_three_digits(t_stract_dict *dict, int remainder, \
	int *result_size);
char	**convert_to_words(t_stract_dict *dict, long long number, \
	int *result_size);
#endif
