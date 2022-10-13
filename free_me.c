/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:53:14 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/10 16:20:08 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
 *free_sudoku releases reserved memory from the 2D array.
 */
void	free_me(int **sudoku)
{
	int	index;

	index = 0;
	while (index < 9)
	{
		free(sudoku[index]);
		index++;
	}
	free(sudoku);
}
