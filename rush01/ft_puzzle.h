/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:09:25 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 18:24:32 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUZZLE_H
# define FT_PUZZLE_H

# include <stdlib.h>
# include <unistd.h>

# define SIZE 4
# define CLUE_COUNT 16

/*
** ft_input.c
*/
int		*ft_parse_input(char *str);

/*
** ft_grid.c
*/
void	ft_init_grid(int grid[SIZE][SIZE]);
void	ft_print_grid(int grid[SIZE][SIZE]);

/*
** ft_util.c
*/
void	ft_rev_arr(int *arr);
int		ft_is_check(int *line, int clue, int reverse);

/*
** ft_validation.c
*/
int		ft_pos_valid(int grid[SIZE][SIZE], int row, int col,
			int height);
int		ft_col_valid(int grid[SIZE][SIZE], int *clues, int col);
int		ft_row_valid(int grid[SIZE][SIZE], int *clues, int row);
int		ft_fin_check(int grid[SIZE][SIZE], int *clues, int row,
			int col);

/*
** ft_solve.c
*/
int		ft_solve(int grid[SIZE][SIZE], int *clues, int pos);

#endif
