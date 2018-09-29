/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:13:32 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/29 15:29:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool	is_unique(char *str);
bool	check_permutation(char *s1, char *s2);
void	URLify(char *str, int true_len);
bool	palindrome_permutation(char *str);

int main(int ac, char **av)
{
	printf("is_unique [%s]? %s\n", av[1], is_unique(av[1]) ? "true" : "false");
	
	return (0);
}
