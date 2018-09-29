/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:08:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/29 09:02:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Is Unique: Implement an algorithm to determine if a string has all unique
**	characters.
*/

#include <stdbool.h>

bool	is_unique(char *str)
{
	bool	unique[127] = {false};
	
	for (int i = 0; str[i]; i++)
	{
		if (unique[str[i]] == true)
			return (false);
		unique[str[i]] = true;	
	}
	return (true);
}

/*
**  What if you can't use any additional data structures?
**	-> Compare each char with every other. O(n2) time, O(1) space.
**	-> Sort with sorting algorithm (must be in-place!) which would take O(nlog(n))
**	time, then compare all neighbours chars. O(nlog(n)) time, O(1) space.
*/
