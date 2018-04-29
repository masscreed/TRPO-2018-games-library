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

int matches_game(char *player1, char *player2){
	int player, matches = 100;
	char value[100];
	player = 1;
	while (1){
		if (player == 1){
			printf("%s ,your turn\n", player1);
			printf("Enter how much matches you want to take\n");
			scanf("%s",value);
			while(correct_match(atoi(value)) == 1){
				scanf("%s", value);
			}
			matches = matches - atoi(value);
			if (matches < 1){
				return 1;
			}
			system ("clear");
			printf("Matches left %d\n", matches);
		}
		if (player == 2){
			printf("%s ,your turn\n", player2);
			printf("Enter how much matches you want to take\n");
			scanf("%s",value);
			while(correct_match(atoi(value)) == 1){
				scanf("%s", value);
			}
			matches = matches - atoi(value);
			if (matches < 1){
				return 2;
			}
			system ("clear");
			printf("Matches left %d\n", matches);
		}
		if (player == 1){
			player = 2;
		} else { 
			player = 1;
		}
	}
	return 0;
}

