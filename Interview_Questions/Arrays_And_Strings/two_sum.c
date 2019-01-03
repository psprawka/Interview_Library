/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 01:06:31 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/29 01:19:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Given an array of integers, return indices of the two numbers such that
**  they add up to a specific target. You may assume that each input would have
**  exactly one solution, and you may not use the same element twice.
*/

#include "libft.h"

int     *two_sum(int *array, int n)
{
    t_ht_table  *ht;
    t_ht_item   *ht_item;
    int         *ret;

    if (!array  || n < 2 || !(ht = ft_init_table_ht(n)))
        return (NULL);

    for (int i = 0; i < n; i++)
    {


    }

    return (NULL);
}

                         