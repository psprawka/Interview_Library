#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	tankPush(tank, 900);
	tankPush(tank, 50);
	tankPush(tank, 110);
	tankPush(tank, 560);
	tankPush(tank, 400);
	printStacks(tank);
	tankPop(tank);
	printStacks(tank);
	tankPop(tank);
	printStacks(tank);
	tankPop(tank);
	printStacks(tank);
	return (0);
}