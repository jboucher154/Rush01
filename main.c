/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:21 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/10 16:17:08 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**read_input(int argc, char **argv, int **sudoku);
void	ft_putstr(char *str);
int		solve_it(int **sudoku, int x, int y);
void	printer(int **sudoku);
void	free_me(int **sudoku);

int	main(int argc, char **argv)
{
	int	**sudoku;

	if (argc != 10)
	{
		ft_putstr("Error\n");
		return (1);
	}
	else
	{
		sudoku = NULL;
		sudoku = read_input(argc, argv, sudoku);
		if (sudoku != NULL && solve_it(sudoku, 0, 0))
			printer(sudoku);
		else
		{
			ft_putstr("Error\n");
			free_me(sudoku);
			return (1);
		}
	}
	free_me(sudoku);
	return (0);
}
