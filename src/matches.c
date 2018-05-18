#include <string.h>
#include <stdlib.h>
#include "matches.h"
#include "theme.h"
#include <stdio.h>
#include <ctype.h>

char *correct_match(char *value)
{
	int i,flag = 0,j;
	for(i = 0;i < 3;i++) {

		if (value[i] == '\n'){
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		j = i;
		for(i = 0;i < j;i++){

			if (!isdigit(value[i])) {
				return NULL;
			}
		}

	} else {
		flush_input_for_match();
		return NULL;
	}
	return value;
}

char *enter_nickname(char *player)
{
	char ch;
	int read = 0,i;
	for (i = 0; i < 25; i++) {
		player[i] = '\0';
	}

	do {

		ch = getchar ();
		player[read] = ch;
		read++;

	} while (ch != '\n' && read != 25);

	return player;
}

int check_nickname(char *player)
{
	int i,flag = 0;
	for(i = 0;i < 25;i++) {

		if (player[i] == '\n'){
			flag = 1;
			break;
		}
	}
	
	if (flag == 0) {

		flush_input_for_match();
		return -2;

	} else {
		return 0;
	}
	
}

int ask_nicknames(char *player1, char *player2)
{
	int flag = 0;
	
	while (1){
		printf(AQUA  BLACKF "Player 1, enter your nickname here\n" DEFAULT);
		printf(AQUA  BLACKF"Maximum is 24 letters\n"DEFAULT);
		printf(GREEN BLACKF);
		player1 = enter_nickname(player1);
		flag = check_nickname(player1);
		if (flag == -2){
			system ("clear");
			printf("Too much letters in a string \n");
			continue;
		} else {
			break;
		}
	}

	while (1){
		printf(AQUA  BLACKF "Player 2, enter your nickname here\n" DEFAULT);
		printf(AQUA  BLACKF"Maximum is 24 letters\n"DEFAULT);
		printf(GREEN BLACKF);
		player2 = enter_nickname(player2);
		flag = check_nickname(player2);
		if (flag == -2){
			system ("clear");
			printf("Too much letters in a string \n");
			continue;
		} else {
			break;
		}
	}

	int count;
	count = strlen(player1);
	player1[count - 1] = '\0';
	count = strlen(player2);
	player2[count - 1] = '\0';
	system ("clear");

	return 0;
}

int matches_turn(char *player, int *matches)
{
	char *value;
	value = calloc(sizeof(char), 3);
	int num;
	printf("%s ,your turn\n", player);
	printf("Enter how much matches you want to take\n");
	while (1) {
		value = enter_matches();
		value = correct_match(value);

		if (value == NULL) {
				printf("Error Input! Too much characters or incorrect symbols\n");
				continue;
		}
		num = atoi(value);

		if (num > 0 && num < 11) {
			break;
		} else {
			system("clear");
			printf("Value is out of range, %s. Enter another\n", player);
			printf("Matches left %d\n", *matches);
			continue;
		}		
	}

	*matches = *matches - num;

	if (*matches < 1){
		return 1;
	}

	system ("clear");
	printf("Matches left %d\n", *matches);

	return 0;
}

int matches_game(char *player1, char *player2)
{
	int win;
	ask_nicknames(player1,player2);
	system ("clear");
	int player, matches = 100;
	player = 1;
	while (1){
		if (player == 1){

			win = matches_turn(player1, &matches);
			if (win == 1){
				system("clear");
				printf("You won,%s. Easy win - Eazy life!\n", player1);
				exit(0);
			}
		}
	
		if (player == 2){

			win = matches_turn(player2, &matches);
			if (win == 1){
				system("clear");
				printf("You won,%s. Easy win - Eazy life!\n", player2);
				exit(0);
			}
		}

		if (player == 1){
			player = 2;

		} else {
			player = 1;
		}
	}
	return 0;
}

void flush_input_for_match()
{
	char c;

	c = getc(stdin);
	while (c != '\n') {
		c = getc(stdin);
	}
}

char *enter_matches(char *player)
{
	char ch;
	char *number = calloc(3, sizeof(char));
	int read = 0;

	do {
		ch = getchar ();

		if (ch == 'q'){
			printf("You entered 'q'. Exit...\n");
			exit(0);
		}

		number [read] = ch;
		read++;
	} while (read != 3 && ch != '\n');

	return number;
}
