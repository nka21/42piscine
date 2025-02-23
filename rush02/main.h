/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketomita <ketomita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:04:49 by ketomita          #+#    #+#             */
/*   Updated: 2025/02/23 23:33:57 by ketomita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define UINT_MAX 4294967295

typedef struct namae2{
	int				fd1;
	int				byte_num;
	int				i;
	int				k;
	int				n;
	char			*buf;
}	t_namae2;
long long			ft_atoi(char *str);
int					count_size(void);
int					count_row(char *str);
int					check_length(char *av);
char				*ft_strdup(char *av);
int					ft_read(unsigned int num);

#endif
