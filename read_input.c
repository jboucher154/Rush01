/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:45:28 by dannguye          #+#    #+#             */
/*   Updated: 2022/07/10 13:59:05 by akurusio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**fillsudoku(int argc, char **argv, int **sudoku);

int	**read_input(int argc, char **argv, int **sudoku)
{
	int	c;
	int	max_index;

	max_index = 9;
	sudoku = (int **) malloc(sizeof(int *) * max_index);
	c = 0;
	while (c < max_index)
	{
		sudoku[c] = (int *) malloc(sizeof(int) * max_index);
		c++;
	}
	return (fillsudoku(argc, argv, sudoku));
}

int	**fillsudoku(int argc, char **argv, int **sudoku)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != '.')
				sudoku[i - 1][j] = argv[i][j] - '0';
			else
				sudoku[i - 1][j] = 0;
			j++;
		}
		if (j != 9)
		{
			sudoku = NULL;
			return (sudoku);
		}
		j = 0;
		i++;
	}
	return (sudoku);
}
