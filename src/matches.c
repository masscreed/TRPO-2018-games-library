#include <string.h>
#include <stdlib.h>
#include "matches.h"
#include "theme.h"
#include <stdio.h>
#include <ctype.h>

#define MATCHES_LEFT (3)
#define TAKE_MATCH (2)
#define YOUR_TURN (1)
#define TOO_LARGE_HEAP (-1)
#define MANY_LETTERS (-2)

int check_match(char *value)
{

	int i,flag = 0,j;
	if(strcmp(value,"q\n") == 0){
		return -4;
	}


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
				return -2;
			}
		}
		
		if (atoi(value) > 10 || atoi(value) < 1) {
			return -3;
		}
	} else {
		return -1;
	}

	return 0;
}

int check_heap (int *heap, int turn)
{
	if(*heap < turn){
		return -1;
	}
	
	if(*heap >= turn){
		return 0;
	}
	
	return 1;
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
		return -2;
	} else {
		return 0;
	}
}

void print_ask_name(char *player, int index)
{
	printf(BLACKF GRAY BOLD "Player %d," DEFAULT
			BLACKF AQUA BOLD " enter your nickname " DEFAULT, index);
	printf(BLACKF BROWN BOLD "(Maximum is 24 letters) -> " DEFAULT);

}

void print_winnner(int win, char *player)
{
	if (win == 1){
		system("clear");
		printf(BLACKF GREEN BOLD "You won," DEFAULT
		BLACKF GRAY BOLD " %s.\n\n" DEFAULT
		BLACKF GREEN BOLD "Eazy win - Eazy life!\n" DEFAULT, player);
		exit(0);
	}
}

void print_over(int i)
{
	if(i == TOO_LARGE_HEAP){
		printf(BLACKF RED BOLD "Value is too large for heap!\n" DEFAULT);
	}
	
	if(i == MANY_LETTERS){
		printf(BLACKF RED BOLD "Too much letters in a string\n" DEFAULT);
	}
}

void print_matches_turn(char *player, int i, int *matches)
{
	if(i == YOUR_TURN){
		printf(BLACKF GRAY BOLD "%s," DEFAULT
			BLACKF AQUA BOLD " your turn\n" DEFAULT, player);
	}

	if(i == TAKE_MATCH){
		printf(BLACKF AQUA BOLD "Enter how much matches you want to take -> "
			DEFAULT);
	}

	if(i == MATCHES_LEFT){
		system ("clear");
		printf(BLACKF BROWN BOLD "Matches left %d\n\n" DEFAULT, *matches);
	}

	
}

void print_flag_errors (int flag)
{
	if (flag == -2) {
		printf(BLACKF RED BOLD "Error Input! Incorrect symbols\n" DEFAULT);
	}

	if (flag == -3) {
		printf(BLACKF RED BOLD "Error Input! Value is out of range\n" DEFAULT);
	}

	if (flag == -4) {
		printf(BLACKF BROWN BOLD "You entered 'q'. Quit...\n" DEFAULT);
		exit(2);
	}

	if (flag == -1) {
		flush_input_for_match();
		printf(BLACKF RED BOLD "Error Input! Too much symbols\n" DEFAULT);
	}
}

char *enter_nickname(char *player)
{
	char ch;
	int read = 0,i;
	for (i = 0; i < 25; i++) {
		player[i] = '\0';
	}

	printf(GRAY BLACKF BOLD);
	do {
		ch = getchar ();
		player[read] = ch;
		read++;

	} while (ch != '\n' && read != 25);
	printf(DEFAULT);

	return player;
}


int ask_nickname(char *player, int index)
{
	int flag = 0, count;
	
	while (1){
		print_ask_name(player, index);

		player = enter_nickname(player);
		flag = check_nickname(player);

		if (flag == -2){
			flush_input_for_match();
			system ("clear");
			print_over(MANY_LETTERS);
			continue;
		} else {
			break;
		}
	}

	count = strlen(player);
	player[count - 1] = '\0';
	
	system("clear");

	return 0;
}

int matches_turn(char *player, int *matches)
{
	char *value;
	value = calloc(sizeof(char), 3);
	int num, flag, check;

	print_matches_turn(player, YOUR_TURN, matches);

	while (1) {
		print_matches_turn(player, TAKE_MATCH, matches);
		value = enter_matches();
		flag = check_match(value);

		if(flag != 0){
			print_flag_errors(flag);
			continue;
		}

		num = atoi(value);

		check = check_heap(matches, num);
		if (check == -1){
			print_over(TOO_LARGE_HEAP);
			continue;
		}

		if (check == 0){
			*matches = *matches - num;

			if(*matches == 0){
				return 1;

			} else {
				print_matches_turn(player, MATCHES_LEFT, matches);
				return 0;
			}
		}
	
	}

	return 2;
}

void matches_game()
{
	int win,player, matches = 100;
	char *player1;
	char *player2;
	player1 = malloc(sizeof(char) * 25);
	player2 = malloc(sizeof(char) * 25);
	ask_nickname(player1, 1);
	ask_nickname(player2, 2);
	system ("clear");
	player = 1;
	while (1){
		if (player == 1){

			win = matches_turn(player1, &matches);
			print_winnner(win, player1);
		}
	
		if (player == 2){

			win = matches_turn(player2, &matches);
			print_winnner(win, player2);
		}

		if (player == 1){
			player = 2;

		} else {
			player = 1;
		}
	}
}

void flush_input_for_match()
{
	char c;

	c = getc(stdin);
	while (c != '\n') {
		c = getc(stdin);
	}
}

char *enter_matches()
{
	char ch;
	char *number = calloc(3, sizeof(char));
	int read = 0;

	do {
		ch = getchar ();
		
		number [read] = ch;
		read++;
	} while (read != 3 && ch != '\n');

	return number;
}
