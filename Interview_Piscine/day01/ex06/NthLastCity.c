/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:25:23 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 21:46:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define t_city struct s_city 

char  *NthLastCity(struct s_city *city, int n)
{
	t_city *end;

	for (end = city; n != 0; n--)
	{
		if (!end)
			return (NULL);
		end = end->next;
	}
	while (end->next)
	{
		end = end->next;
		city = city->next;
	}
	return (city->name);
}