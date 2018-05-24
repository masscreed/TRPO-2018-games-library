#include <stdio.h>
#include "bulls.h"
#include "matches.h"
#include <string.h>
#include <stdlib.h>
#include <theme.h>

void print_help();

int main(int argc, char *argv[])
{
	system("clear");
	if (argc == 2) {
		if (strcmp("matches\0", argv[1]) == 0) {
			matches_game();
		} else if (strcmp("bulls\0", argv[1]) == 0) {
			bulls_game();
		} else {
			printf(BLACKF RED BOLD "\t       WRONG ARGUMENT\n\n" DEFAULT);
			print_help();
			return -1;
		}
	} else if (argc == 1){
		printf(BLACKF RED BOLD "\t       NO ARGUMENTS\n\n" DEFAULT);
		print_help();
		return -1;
	} else {
		printf(BLACKF RED BOLD "\t    TOO MUCH ARGUMENTS\n\n" DEFAULT);
		print_help();
		return -1;
	}

	return -1;
}

void print_help() {
	printf(BLACKF AQUA BOLD "\t\t***HELP***\n"
							"\t\t||||||||||\n" DEFAULT);

	printf(BLACKF BROWN BOLD "Use arguments:\n"
			BLACKF BROWN BOLD "    <bulls> for start game \"Bulls and cows\"\n"
			BLACKF BROWN BOLD "    <matches> for start game \"100 Matches\"\n");
	printf(BLACKF AQUA BOLD "\t\t||||||||||\n"
							"\t\t||||||||||\n" DEFAULT);

}
