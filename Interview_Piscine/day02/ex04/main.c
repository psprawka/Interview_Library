#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"
#define NUMBER_OF_USTENSILS 15

int main(void)
{
	unsigned char *utensils;
	
	int n = 100;
	utensils = genRandomUstensils(&n); //if param == 0, the length of the list will be random between 1 and 1 million
	printUtensils(utensils, n);

	printf("sorting using count sort...\n");
	countSort(utensils, n);
	printUtensils(utensils, n);
	return (0);
}


void printUtensils(unsigned char *utensils, int n)
{
	int order = 1;
	printf("{ ");
	for (int i = 0; i < n; i++){
		printf("%d%s", utensils[i], (i + 1 < n) ? ", " : " ");
		if (i >= 1 && utensils[i - 1] > utensils[i])
			order = 0;
	}
	printf("} (%s)\n", (order) ? "sorted" : "not sorted");
}


unsigned char *genRandomUstensils(int *n)
{
	unsigned char *utensils;

	srand(time(NULL));
	if ((*n) <= 0 || (*n) > 1000000000){
		(*n) = rand() % 1000000 + 1; //generating int between 1 and 1.000.000
	}
	utensils = malloc(sizeof(unsigned char) * (*n));
	for (int i = 0; i < (*n); i++){
		utensils[i] = rand() % NUMBER_OF_USTENSILS + 1;
	}
	return (utensils);
}
