/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:11:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 18:54:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Zero matrix: Write an algorithm such as that if an element in an MxN
**	matrix is 0, its entire row and column are set to 0.
*/

#include <stdbool.h>
#include <stdlib.h>

void	zero_matrix(int **matrix, int rows, int columns)
{
	bool	*arr_row;
	bool	*arr_column;
	
	if (!(arr_column = (bool *)calloc(columns, sizeof(bool))) ||
		!(arr_row = (bool *)calloc(rows, sizeof(bool))))
		return ;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j])
				continue ;
			arr_row[i] = true;
			arr_column[j] = true;		
		}
	}
	
	for (int i = 0; i < rows; i++)
	{
		if (!arr_row[i])
			continue ;
		for (int j = 0; j < columns; j++)
			matrix[i][j] = 0;
	}

	for (int j = 0; j < columns; j++)
	{
		if (!arr_column[j])
			continue ;
		for (int i = 0; i < rows; i++)
			matrix[i][j] = 0;
	}
}
