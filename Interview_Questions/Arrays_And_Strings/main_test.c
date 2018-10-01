/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:13:32 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/30 10:06:45 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool	is_unique(char *str);
bool	check_permutation(char *s1, char *s2);
void	URLify(char *str, int true_len);
bool	palindrome_permutation(char *str);
char	*string_compression(char *str);
bool	one_away(char *s1, char *s2);

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
	
	memmove(&(test[len]), "        ", 8);
	URLify(test, len);
	printf("URLift [%s][%d]? [%s]\n", av[1], len, test);
	
	/* ========================================================================================== */
	
	return (0);
}
