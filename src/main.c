#include <string.h>
#include <stdlib.h>
#include "matches.h"
#include <stdio.h>

int main()
{
	char player1[100], player2[100];
	nicknames(player1, player2);
	printf("Nickname of Player 1 :%s\n", player1);
	printf("Nickname of Player 2 :%s\n", player2);
	return 0;
}

