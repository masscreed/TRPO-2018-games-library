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
		printf(DEFAULT RED BLACKF "ERROR\n" DEFAULT);
		return NULL;
	}
	int read = 0;

	printf(AQUA BLACKF "%s enter your number: " DEFAULT, player);
	printf(GREEN BLACKF);

	do {
		ch = getchar ();

		if (!isdigit(ch) && ch != '\n') {
			printf(DEFAULT RED BLACKF "ERROR IN INPUT\n" DEFAULT);
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
		printf(DEFAULT RED BLACKF "ERROR IN INPUT (not 4-digit number) \n" DEFAULT);
		return -1;
	}
}
