/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:11:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 18:26:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Rotate matrix: Given an image represented by NxN matrix, where each pixel
**	of matrix is 4 bytes, write a method to rotate an image by 90 degrees.
**	Can you do it in place?
*/

void	swap_matrix(int **matrix, int n, int i, int j)
{
	int		tmp;

	tmp = matrix[i][j];
	matrix[i][j] = matrix[n - j][i];
	matrix[n - j][i] = matrix[n - i][n - j];
	matrix[n - i][n - j] = matrix[j][n - i];
	matrix[j][n - i] = tmp;
}

void	rotate_matrix(int **matrix, int n)
{
	int		tmp;
	
	for (int i = 0; i < n - i; i++)
	{
		for (int j = i; j < n - i - 1; j++)
			swap_matrix(matrix, n - 1, i, j);
	}
}
