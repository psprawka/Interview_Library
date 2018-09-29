#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	int arr[] = {10, -2, 2, 21, -5, 42, 3, -6, 17, 11};
	int arr2[] = {12, 1, 78, 90, 57, 89, 56};
	int n, n2;
	int k, k2, k3;
	struct s_max *res;

	res = NULL;
	n = 10, n2 = 7;
	k = 4, k2 = 3, k3 = 2;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	res = maxSlidingWindow(arr, n, k);
	if (res) {
		for (int i = 0; i < res->length; i++)
			printf("%d ", res->max[i]);
		printf("\n");
	}

	for (int i = 0; i < n2; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	res = maxSlidingWindow(arr2, n2, 3);
	if (res) {
		for (int i = 0; i < res->length; i++)
			printf("%d ", res->max[i]);
		printf("\n");
	}

	return (0);
}

