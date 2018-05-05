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
		printf(DEFAULT RED BLACKF BOLD "ERROR\n" DEFAULT);
		return NULL;
	}
	int read = 0;

	printf(AQUA BLACKF BOLD "%s enter number: " DEFAULT, player);
	printf(GREEN BLACKF BOLD);

	do {
		ch = getchar ();

		if (!isdigit(ch) && ch != '\n') {
			printf(DEFAULT RED BLACKF BOLD "ERROR IN INPUT\n" DEFAULT);
			flush_input();
			return NULL;
		}

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
	if (number[4] == '\n') {
		number[4] = '\0';
		return 0;
	} else {
		if (!strchr(number, '\n')) {
			flush_input();
		}
		printf(DEFAULT RED BLACKF BOLD "ERROR IN INPUT (not 4-digit number) \n" DEFAULT);
		return -1;
	}
}

int guessing(char *player, char *number) {
	char * input;
	int bucow;

	while (1) {
		input = enter_number(player);

		if (input != NULL) {
			if (!check_number(input)) {
				break;
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


