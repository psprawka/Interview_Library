/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compression.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:10:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/29 22:43:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	String Compression: Implement a function to perform basic string compression
**	using the counts of repeated characters - the string "aaabbccccdddaa" would
**	become a3b2c4d3a2. If the new string is greater than old one, return
**	an initial string. Assume there are only letters.
*/

#include <stdlib.h>

int		count_len(int start)
{
	int ret;

	for (ret = 0; start != 0; ret++)
		start /= 10;
	return (ret + 1);	// 1 for a character
}

char	*create_string(char *str, int *letters, int len, int new_len)
{
	char	*new, *nb;
	int		start = 0, i = 0;
	
	if (!(new = (char *)calloc(new_len + 1, sizeof(char))))
		return (NULL);
	while (start < len + 1)
	{
		new[i] = str[start];
		nb = itoa(letters[start]);
		memcpy(&(new[i]), nb, strlen(nb));
		start += letters[start];
	}
	return (new);
}

char	*string_compression(char *str)
{
	int		letters[127 - 65];
	int		len, new_len, start = 0;
	char	letter;

	for (len = 0; str[len]; len++)
	{
		for (start = 0, letter = str[len]; str[len] && str[len] == letter; len++)
			start++;
		letters[letter] = start;
		len += start;
		new_len += count_len(start);
	}
	if (new_len <= len)
		return (str);
	return (create_string(str, letters, len, new_len));
}
