/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   URLify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:09:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/29 15:29:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	URLify: Write a function to replace all spaces with %20. Assume that given
**	string has sufficient space at the end to hold additional chars and that
**	you are given the "true" length of string.
*/

void	URLify(char *str, int true_len)
{
	int		len, spaces = 0;
	
	for (int i = 0; i < true_len; i++)
		if (str[i] == ' ')
			spaces++;
	
	for (int len = true_len - 1 + spaces * 3; len >= 0; len-- && true_len--)
	{
		if (str[true_len] == ' ')
		{
			str[len--] = '0';
			str[len--] = '2';
			str[len] = '%';
		}
		else
			str[len] = str[true_len];
	}
}