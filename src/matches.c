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

int nicknames(char *player1, char *player2)
{
	printf(AQUA  BLACKF "Player 1, enter your nickname here\n" DEFAULT);
	printf(AQUA  BLACKF"Maximum is 24 letters\n"DEFAULT);
	printf(GREEN BLACKF);
	char ch;
	int read = 0,i;
	do {
		ch = getchar ();
		if (read >= 25) {
			flush_input_for_match();
			for(i = 0; i < 25; i++) {
				player1[i] = '\0';
				player2[i] = '\0';
			}
			return -1;
		}
		player1[read] = ch;

		read++;
	} while (ch != '\n');

	printf(DEFAULT);
	int count;
	count = strlen(player1);
	player1[count - 1] = '\0';
	printf(AQUA BLACKF "Player 2, enter your nickname here\n" DEFAULT);
	printf(AQUA  BLACKF"Maximum is 24 letters\n"DEFAULT);
	printf(GREEN BLACKF);
	read = 0;
	do {
		ch = getchar ();
		if (read >= 25) {
			flush_input_for_match();
			for(i = 0; i < 25; i++) {
				player1[i] = '\0';
				player2[i] = '\0';
			}
			return -1;
		}
		player2 [read] = ch;

		read++;
	} while (ch != '\n');

	printf(DEFAULT);
	count = strlen(player2);
	player2[count - 1] = '\0';
	system ("clear");
	return 0;
}

int matches_game(char *player1, char *player2)
{
	int flag, num;
	while (1){
		flag = nicknames(player1, player2);
		if (flag == -1){
			system ("clear");
			printf("Too much letters in a string \n");
			continue;
		} else {
			break;
		}
	}
	system ("clear");
	int player, matches = 100;
	char *value;
	value = calloc(sizeof(char), 3);
	player = 1;
	while (1){

		if (player == 1){
			printf("%s ,your turn\n", player1);
			printf("Enter how much matches you want to take\n");
			while (1) {
				value = enter_matches();
				value = correct_match(value);
				if (value == NULL) {
					printf("Error Input!\n");
					continue;
				}
				num = atoi(value);

				if (num > 0 && num < 11) {
					break;
				} else {
					system("clear");
					printf("Value is out of range, %s. Enter another\n", player1);
					printf("Matches left %d\n", matches);
					continue;
				}		
			}

			matches = matches - num;
			if (matches < 1){
				return 1;
			}
			system ("clear");
			printf("Matches left %d\n", matches);
		}
		if (player == 2){
			printf("%s ,your turn\n", player2);
			printf("Enter how much matches you want to take\n");
			while (1) {
				value = enter_matches();
				value = correct_match(value);
				if (value == NULL) {
					printf("Error Input!\n");
					continue;
				}
				num = atoi(value);

				if (num > 0 && num < 11) {
					break;
				} else {
					system("clear");
					printf("Value is out of range, %s. Enter another\n", player2);
					printf("Matches left %d\n", matches);
					continue;
				}		
			}
			matches = matches - num;
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
