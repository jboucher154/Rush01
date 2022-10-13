/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:09:06 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/10 13:37:51 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_placement(int **sudoku, int row, int col, int to_check)
{
	int	index;
	int	box_row;
	int	box_col;

	index = 0;
	while (index < 9)
	{
		if (sudoku[row][index] == to_check || sudoku[index][col] == to_check)
			return (0);
		index++;
	}
	box_row = ((row / 3) * 3);
	while (box_row <= ((row / 3) * 3 + 2))
	{
		box_col = ((col / 3) * 3);
		while (box_col <= ((col / 3) * 3 +2))
		{
			if (to_check == sudoku[box_row][box_col])
				return (0);
			box_col++;
		}
		box_row++;
	}
	return (1);
}
