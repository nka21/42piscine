/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:36:29 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/16 17:16:09 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puzzle.h"

int	main(int argc, char **argv)
{
	int	grid[SIZE][SIZE];
	int	*clues;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	clues = ft_parse_input(argv[1]);
	if (!clues)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_init_grid(grid);
	if (ft_solve(grid, clues, 0))
		ft_print_grid(grid);
	else
		write(1, "Error\n", 6);
	free(clues);
	return (0);
}
