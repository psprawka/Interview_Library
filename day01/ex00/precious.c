/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 01:53:07 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 04:22:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

# define	t_node struct s_node


// ----------------------------- LIBFT FUNCTIONS -------------------------------

typedef struct	s_list
{
	t_node	*head;
	t_node	*tail;
}				t_list;

int		add_dblist_tail(t_list *dblist, t_node *new)
{
	// printf("add dblist\n");
	if (!dblist)
		return (EXIT_FAILURE);
	// printf("check for tail\n");
	if (!(dblist->tail))
	{
		dblist->head = new;
		dblist->tail = new;
		return (EXIT_SUCCESS);
	}
	// printf("tail exists\n");
	dblist->tail->next = new;
	new->prev = dblist->tail;
	dblist->tail = new;
	return (EXIT_SUCCESS);
}

int		add_dblist_head(t_list *dblist, t_node *new)
{
	// printf("add dblist\n");
	if (!dblist)
		return (EXIT_FAILURE);
	if (!dblist->head)
	{
		dblist->head = new;
		dblist->tail = new;
		return (EXIT_SUCCESS);
	}
	dblist->head->prev = new;
	new->next = dblist->head;
	dblist->head = new;
	return (EXIT_SUCCESS);
}


// ---------------------------------- EX00 -------------------------------------

t_node	*init_node(char c)
{
	t_node	*new;

	// printf("init node\n");
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	bzero(new, sizeof(t_node));
	new->c = c;
	new->prev = NULL; 
	new->next = NULL;
	// printf("node created\n");
	return (new);
}

void	createList(t_list *dblist)
{
	int		i;
	t_node	*new;
	
	i = 0;
	while (CS[i])
	{
		// printf("inside while createList\n");
		new = init_node(CS[i]);
		add_dblist_tail(dblist, new);
		i++;
	}
	// printf("left while createList\n");
	dblist->tail->next = dblist->head;
	dblist->head->prev = dblist->tail;
	
}

char	*decodeMsg(t_list *dblist, int *text, int size)
{
	t_node	*head;
	char	*msg;

	if (!(msg = (char *)malloc(size + 1)))
		return (NULL);
	bzero(msg, size + 1);
	head = dblist->head;
	for (int i = 0; i < size; i++)
	{
		if (text[i] < 0)
			for (int j = text[i]; j != 0; j++) 
				head = head->prev;
		else
			for (int j = text[i]; j != 0; j--) 
				head = head->next;
		msg[i] = head->c;
	}
	return (msg);
}

char	*precious(int *text, int size)
{
	t_list	*dblist;
	
	dblist = (t_list *)malloc(sizeof(t_list));
	dblist->tail = NULL;
	dblist->head = NULL;
	createList(dblist);
	// return ("lol");
	return(decodeMsg(dblist, text, size));
}

