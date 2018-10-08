/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:13:32 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 22:01:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


bool	is_unique(char *str);
bool	check_permutation(char *s1, char *s2);
void	URLify(char *str, int true_len);
bool	palindrome_permutation(char *str);
char	*string_compression(char *str);
bool	one_away(char *s1, char *s2);
void	rotate_matrix(int **matrix, int n);
void	zero_matrix(int **matrix, int rows, int columns);
bool	string_rotation(char *s1, char *s2);

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: ./a.out str1 str2 ...\n");
		return (0);
	}
	
	/* =================================== ARRAYS AND STRINGS =================================== */

	// printf("is_unique [%s]? %s\n", av[1], is_unique(av[1]) ? "true" : "false");
	// printf("check_permutation [%s][%s]? %s\n", av[1], av[2], check_permutation(av[1], av[2]) ? "true" : "false");
	// printf("palindrome_permutation [%s]? %s\n", av[1], palindrome_permutation(av[1]) ? "true" : "false");
	// printf("one_away [%s][%s]? %s\n", av[1], av[2], one_away(av[1], av[2]) ? "true" : "false");
	// printf("string_compression [%s]: [%s]\n", av[1], string_compression(av[1]));
	
	char	*test = strdup(av[1]);
	int		len = strlen(test);
	
	// memmove(&(test[len]), "        ", 8);
	// URLify(test, len);
	// printf("URLift [%s][%d]? [%s]\n", av[1], len, test);
	
	
	/////////////////////////////// 1.7 /////////////////////////////////////////////
	
	// int		size = 5;
	// int		**matrix;

	// if (!(matrix = (int **)malloc(sizeof(int *) * size)))
	// 	return (0);
	// for (int i = 0; i < size; i++)
	// {
	// 	matrix[i] = (int *)malloc(sizeof(int) * size);
	// 	for (int j = 0; j < size; j++)
	// 	{
	// 		matrix[i][j] = (i * size) + j;
	// 		printf("%d ", (i * size) + j);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n");
	// rotate_matrix(matrix, size);
	// for (int i = 0; i < size ; i++)
	// {
	// 	for (int j = 0; j < size; j++)
	// 		printf("%d ", matrix[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
	

	//////////////////////////////// 1.8 /////////////////////////////////////////

	// int		rows = 5, columns = 6;
	// int		**matrix;
	

	// srand(time(0));
	// if (!(matrix = (int **)malloc(sizeof(int *) * rows)))
	// 	return (0);
	// printf("\n");
	// for (int i = 0; i < rows; i++)
	// {
	// 	matrix[i] = (int *)malloc(sizeof(int) * columns);
	// 	for (int j = 0; j < columns; j++)
	// 	{
	// 		matrix[i][j] = rand() % (rows * 2);
	// 		printf("%d ", matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n");
	// zero_matrix(matrix, rows, columns);
	// for (int i = 0; i < rows ; i++)
	// {
	// 	for (int j = 0; j < columns; j++)
	// 		printf("%d ", matrix[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
	
	//////////////////////////////// 1.8 /////////////////////////////////////////

	// char *s1 = "water bottle";
	// char *s2 = "bottlewater ";
	// char *s2fake = "bottlewater";

	// printf("s1:[%s] | s2: [%s] | String rotation? %s\n", s1, s2, string_rotation(s1, s2) ? "true" : "false");
	// printf("s1:[%s] | s2: [%s] | String rotation? %s\n", s1, s2fake, string_rotation(s1, s2fake) ? "true" : "false");
	
	/* ========================================================================================== */
	
	return (0);
}
