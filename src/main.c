#include <stdio.h>
#include "bulls.h"
#include "matches.h"
#include <string.h>
#include <stdlib.h>

int main()
{
	char *pl1;
	char *pl2;
	pl1 = calloc(sizeof(char), 25);
	pl2 = calloc(sizeof(char), 25);
	matches_game(pl1, pl2);
	return 0;
}
