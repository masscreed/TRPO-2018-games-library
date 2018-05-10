#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <theme.h>
#include <ctype.h>
#include <string.h>
#include "bulls.h"


int first_player() {

	int random;

	srand(time(NULL));

	random = (rand() % 1000) + 1;

	if ((random % 2) == 0) {
		return 1;
	} else {
		return 2;
	}

}

char *enter_number(char *player) {
	char ch;
	char *number = calloc(5, sizeof(char));
	if (number == NULL) {
		return NULL;
	}
	int read = 0;

	printf(AQUA BLACKF BOLD "%s enter number: " DEFAULT, player);
	printf(GREEN BLACKF BOLD);

	do {
		ch = getchar ();

		number [read] = ch;

		read++;
	} while (read != 5 && ch != '\n');

	printf(DEFAULT);

	return number;
}

void flush_input() {
	char c;

	c = getc(stdin);
	while (c != '\n') {
		c = getc(stdin);
	}
}

int check_number(char *number) {

	for (int i = 0; i < 5; i++) {
		if (!isdigit(number[i]) && number[i] != '\n') {
			if (!strchr(number, '\n')) {
				flush_input();
			}
			return -1;
		}
	}

	if (number[4] == '\n') {
		number[4] = '\0';
		for (int i = 0; i < 4 ; i++) {
			for (int j = 0; j < 4; j++) {
				if (number[i] == number[j] && i != j) {
					return -2;
				}
			}
		}
		return 0;
	} else {
		if (!strchr(number, '\n')) {
			flush_input();
		}
		return -3;
	}
}

int guessing(char *player, char *number) {
	char * input;
	int bucow = 0;

	while (1) {
		input = enter_number(player);

		if (input != NULL) {
			int error = check_number(input);
			if (!error) {
				break;
			} else {
				print_error(error);
				continue;
			}
		} else {
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

void print_bulls_cows(int bullcow) {
	int bulls = bullcow / 10;
	int cows = bullcow % 10;

	printf(BLACKF BOLD RED "Bulls: " CBLACKF BOLD PURPLE "%d" DEFAULT "\n", bulls);
	printf(BLACKF BOLD GREEN "Cows: " CBLACKF BOLD PURPLE "%d" DEFAULT "\n", cows);
}

void print_error(int error) {
	if (error == -1) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (letters in input) \n" DEFAULT);
	} else if (error == -2) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (numbers repeats) \n" DEFAULT);
	}  else if (error == -3) {
		printf(RED BLACKF BOLD "ERROR IN INPUT (not 4-digit number) \n" DEFAULT);
	}
}


