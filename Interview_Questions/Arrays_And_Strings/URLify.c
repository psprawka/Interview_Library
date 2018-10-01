/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   URLify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:09:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/30 21:23:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	URLify: Write a function to replace all spaces with %20. Assume that given
**	string has sufficient space at the end to hold additional chars and that
**	you are given the "true" length of string.
*/
#include <stdio.h>

void	URLify(char *str, int len)
{
	int		new_len, spaces = 0;
	
	for (int i = 0; i < len; i++)
		if (str[i] == ' ')
			spaces++;
	
	len -= 1;
	for (int new_len = len - spaces + spaces * 3; len >= 0; new_len-- && len--)
	{
		if (str[len] == ' ')
		{
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len] = '%';
		}
		else
			str[new_len] = str[len];
	}
}