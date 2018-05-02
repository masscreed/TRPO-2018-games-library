#include <stdio.h>
#include "bulls.h"

int main()
{
	int priority;

	priority = first_player();

	printf("Number of first player is %d\n", priority);

	return 0;
}
