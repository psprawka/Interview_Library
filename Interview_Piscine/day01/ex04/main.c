#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	struct s_queue *queue;

	if (ac < 2)
	{
		printf("Usage: ./queue word1 ...\n");
		return (0);
	}

	queue = queueInit();
	printf("\n---------------- ENQUEUEING ARGV -----------------\n\n");
	for (int i = 1; av[i] != NULL; i++)
	{
		printf("ENQUEUEING ARGV --> [%s]\n", av[i]);
		enqueue(queue, av[i]);
	}
	printf("\n----------------- ARGV ENQUEUED -------------------\n\n");

	printf("---------------- DEQUEUEING QUEUE -----------------\n\n");
	while (!isEmpty(queue))
	{
		printf("PEEKING QUEUE --> [%s]\n", peek(queue));
		printf("DEQUEUEING QUEUE --> [%s]\n\n", dequeue(queue));
	}
	printf("----------------- QUEUE DEQUEUED -----------------\n\n");

	return (0);
}
