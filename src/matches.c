#include <string.h>
#include <stdlib.h>
#include "matches.h"
#include "theme.h"
#include <stdio.h>

int correct_match (int value){
	if (value > 10 || value < 1){
		printf("Value is not correct\n");
		return 1;
	}
	
	return 0;
}	

int nicknames(char *player1, char *player2)
{
	printf(AQUA  BLACKF "Player 1, enter your nickname here\n" DEFAULT);
	printf(GREEN BLACKF);
	fgets(player1, 100, stdin);
	printf(DEFAULT);
	int count;
	count = strlen(player1);
	player1[count - 1] = '\0';
	printf(AQUA BLACKF "Player 2, enter your nickname here\n" DEFAULT);
	printf(GREEN BLACKF);
	fgets(player2, 100, stdin);
	printf(DEFAULT);
	count = strlen(player2);
	player2[count - 1] = '\0';
	system ("clear");
	return 0;
}

