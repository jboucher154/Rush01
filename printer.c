/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:30:13 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/10 13:35:15 by akurusio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// printer takes a pointer to sudoku array and uses put_char to print
// to standard output each row of the array.
void	printer(int **sudoku)
{
	int	row;
	int	col;
	int	max_index;

	max_index = 9;
	row = 0;
	while (row < max_index)
	{
		col = 0;
		while (col < max_index)
		{
			ft_putchar(sudoku[row][col] + '0');
			if (col == max_index - 1)
				ft_putchar('\n');
			else
				ft_putchar(' ');
			col++;
		}
		row++;
	}
}
