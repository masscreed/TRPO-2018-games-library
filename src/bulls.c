#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <theme.h>
#include <ctype.h>
#include <string.h>
#include "bulls.h"
#include "matches.h"


//Input functions
char *enter_number(char *player) {
	char ch;
	char *number = calloc(5, sizeof(char));
	if (number == NULL) {
		return NULL;
	}
	int read = 0;

	print_ask_number(player);

	printf(GRAY BLACKF BOLD);
	do {
		ch = (char) getchar ();

		number [read] = ch;

		read++;
	} while (read != 5 &&  ch != '\n');
	printf(DEFAULT);

	return number;
}


//Game logic functions
void bulls_game() {
	system("clear");

	char player1[25];
	char player2[25];

	ask_nickname(player1, 1);
	ask_nickname(player2, 2);

	char *p1_number = create_player_num(player1);
	system("clear");
	char *p2_number = create_player_num(player2);
	system("clear");

	int priority = first_player();

	if (priority == 1) {
		turns_loop(player1, player2, p1_number, p2_number);
		exit(0);
	} else {
		turns_loop(player2, player1, p2_number, p1_number);
		exit(0);
	}
}

int first_player() {

	int random;
	srand(time(NULL));

	random = (rand() % 1000) + 1;

	return ((random % 2) == 0) ? 1 : 2;
}

char *create_player_num(char *player) {
	char *input = NULL;

	print_creating_message();

	while (1) {
		input = enter_number(player);

		if (input != NULL) {
			int error = check_number(input);

			if (error) {
				print_error(error);
				if (error == NOT_4_DIGIT_MORE) {
					flush_input();
				}
				continue;
			}

			return input;
		} else {
			print_error(NULL_ERROR);
			continue;
		}
	}
}

void turns_loop(char *player1, char *player2, char *p1_number, char *p2_number) {
	int turn = 1;

	while (1) {
		if (turn == 1) {
			print_priority(player1);
		} else if ((turn - 1) % 4 == 0) {
			print_line();
			print_priority(player1);
		}

		print_turn(turn);
		if (make_turn(player1, p2_number)) {
			print_last_chance(player1, player2);

			if (make_turn(player2, p1_number)) {
				system("clear");
				print_draw_message(player2, player1, p2_number, p1_number);
			} else {
				system("clear");
				print_win_message(player1, player2, p1_number, p2_number);
			}

			return;
		} else {
			turn++;

			print_turn(turn);
			if (make_turn(player2, p1_number)) {
				system("clear");
				print_win_message(player2, player1, p2_number, p1_number);
				return;
			} else {
				turn++;
				continue;
			}
		}
	}
}

int make_turn(char *player, char *number) {
	int bulls = 0;
	int cows = 0;

	int bullcow = guessing(player, number);
	print_bulls_cows(bullcow);
	find_out_bull_cow(&bulls, &cows, bullcow);

	return (bulls == 4) ? 1 : 0;
}

int guessing(char *player, char *number) {
	char *input = NULL;
	int bucow = 0;

	while (1) {
		input = enter_number(player);

		if (input != NULL) {
			int error = check_number(input);

			if (error) {
				print_error(error);
				if (error == NOT_4_DIGIT_MORE) {
					flush_input();
				}
				continue;
			}

			break;
		} else {
			print_error(NULL_ERROR);
			continue;
		}
	}

	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4; j++) {
			if (input[i] == number[j] && i == j) {
				bucow += 10;
			} else if (input[i] == number[j] && i != j) {
				bucow ++;
			}
		}
	}

	return bucow;
}

void find_out_bull_cow(int *bulls, int *cows, int bullcow) {
	*bulls = bullcow / 10;
	*cows = bullcow % 10;
}


//Output functions
void print_error(int error) {
	if (error == SMBL_IN_INPUT) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (letters in input)\n" DEFAULT);
	} else if (error == DIGITS_REPEATS) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (numbers repeats)\n" DEFAULT);
	}  else if (error == NOT_4_DIGIT_LESS) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (not 4-digit number(digits < 4)\n" DEFAULT);
	} else if (error == NOT_4_DIGIT_MORE) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (not 4-digit number)(digits > 4)\n" DEFAULT);
	} else if (error == NULL_ERROR) {
		printf(RED BLACKF BOLD "ERROR IN ALLOCATION (calloc)\n" DEFAULT);
	}
}

void print_priority(char *player) {
	printf(BLACKF GRAY BOLD "%s" DEFAULT
		   BLACKF AQUA BOLD " START GAME\n\n" DEFAULT, player);
}

void print_turn(int turn) {
	printf(BLACKF GRAY BOLD "%d" DEFAULT
		   BLACKF BROWN BOLD " TURN\n\n" DEFAULT, turn);
}

void print_bulls_cows(int bullcow) {
	int bulls = bullcow / 10;
	int cows = bullcow % 10;

	printf(BLACKF BOLD RED "Bulls: " CBLACKF BOLD PURPLE "%d\n" DEFAULT, bulls);
	printf(BLACKF BOLD BROWN "Cows: " CBLACKF BOLD PURPLE "%d\n\n" DEFAULT, cows);
}

void print_draw_message(char *saved, char *second, char *sav_num, char *sec_num) {
	printf(BLACKF BROWN BOLD "DRAW" DEFAULT
		   BLACKF GRAY BOLD " (%s guessed %s number on" DEFAULT
		   BLACKF BROWN BOLD " LAST CHANCE" DEFAULT
		   BLACKF GRAY BOLD ") \n\n" DEFAULT, saved, second);

	print_player_and_num(saved, sav_num);
	print_player_and_num(second, sec_num);
}

void print_win_message(char *winner, char *loser, char *win_num, char *l_num) {
	printf(BLACKF GRAY BOLD "%s" DEFAULT
		   BLACKF GREEN BOLD " WIN (GJ)\n\n" DEFAULT, winner);
	print_player_and_num(winner, win_num);
	print_player_and_num(loser, l_num);
}

void print_player_and_num(char *player, char *number) {
	printf(BLACKF GRAY BOLD "%s" DEFAULT
		   BLACKF AQUA BOLD " number was ->" DEFAULT
		   BLACKF GRAY BOLD " %s\n" DEFAULT, player, number);
}

void print_creating_message() {
	printf(BLACKF AQUA BOLD "CREATING PLAYER SECRET NUMBER FOR GAME\n\n" DEFAULT);
}

void print_line() {
	printf(BLACKF BROWN BOLD);
	for (int i = 0; i < 80; i++) {
		printf("-");
	}
	printf("\n" DEFAULT);
}

void print_last_chance(char *player1, char *player2) {
	printf(BLACKF GRAY BOLD "%s" DEFAULT
		   BLACKF AQUA BOLD " guessed" DEFAULT
		   BLACKF GRAY BOLD " %s" DEFAULT
		   BLACKF AQUA BOLD " number\n" DEFAULT, player1, player2);
	printf(BLACKF BROWN BOLD "LAST CHANCE FOR" DEFAULT
		   BLACKF GRAY BOLD " %s\n\n" DEFAULT, player2);
}

void print_ask_number(char *player) {
	printf(BLACKF GRAY BOLD "%s" DEFAULT
		   BLACKF AQUA BOLD" enter number: " DEFAULT, player);
}


//Additional functions
void flush_input() {
	char c;

	c = (char) getc(stdin);
	while (c != '\n') {
		c = (char) getc(stdin);
	}
}


//Input logic functions
int check_number(char *number) {

	if (!strchr(number, '\n')) {
		return NOT_4_DIGIT_MORE;
	}

	int i;
	for (i = 0; number[i] != '\n'; i++) {
		if (!isdigit(number[i])) {
			return SMBL_IN_INPUT;
		}
	}

	if (i != 4) {
		return NOT_4_DIGIT_LESS;
	} else {
		for (i = 0; i < 4 ; i++) {
			for (int j = 0; j < 4; j++) {
				if (number[i] == number[j] && i != j) {
					return DIGITS_REPEATS;
				}
			}
		}
	}

	return 0;
}
