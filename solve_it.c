/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:41:42 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/10 13:31:20 by akurusio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns 1 if success (sudoku solved), otherwise 0.
int	solve_it(int **sudoku, int x, int y);

// Returns 1 if a placement is valid, otherwise 0.
int	valid_placement(int **sudoku, int x, int y, int n);

int	existing_digit(int **sudoku, int x, int y);
int	new_digit(int **sudoku, int x, int y);

// case of existing digit: go further in sudoku field
int	existing_digit(int **sudoku, int x, int y)
{
	int	max_index;

	max_index = 9;
	if ((y + 1) < max_index)
		return (solve_it(sudoku, x, y + 1));
	else if ((x + 1) < max_index)
		return (solve_it(sudoku, x + 1, 0));
	else
		return (1);
}

// case of 0 digit: checks digits 1..9
int	new_digit(int **sudoku, int x, int y)
{
	int	max_index;
	int	digit;

	max_index = 9;
	digit = 1;
	while (digit <= max_index)
	{
		if (valid_placement(sudoku, x, y, digit))
		{
			sudoku[x][y] = digit;
			if (solve_it(sudoku, x, y))
				return (1);
			else
				sudoku[x][y] = 0;
		}
		digit++;
	}
	return (0);
}

// Returns 1 if the solution is found, otherwise 0.
// Parameters: sudoku field, row, column.
int	solve_it(int **sudoku, int x, int y)
{
	int	max_index;

	max_index = 9;
	if (x >= max_index || y >= max_index)
		return (1);
	else
	{
		if (sudoku[x][y] != 0)
			return (existing_digit(sudoku, x, y));
		else
			return (new_digit(sudoku, x, y));
		return (0);
	}
}
