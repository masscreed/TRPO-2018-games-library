#include <stdio.h>
#include "bulls.h"
#include "matches.h"
#include <string.h>
#include <stdlib.h>
#include <theme.h>

#define WRONG_ARG (-1)
#define NO_ARG (-2)
#define TOO_MUCH_ARG (-3)

void print_help();
void print_arg_error(int error);

int main(int argc, char *argv[])
{
	system("clear");

	if (argc == 2) {
		if (strcmp("matches\0", argv[1]) == 0) {
			matches_game();
		} else if (strcmp("bulls\0", argv[1]) == 0) {
			bulls_game();
		} else {
			print_arg_error(WRONG_ARG);
			print_help();
			return -1;
		}
	} else if (argc == 1){
		print_arg_error(NO_ARG);
		print_help();
		return -1;
	} else {
		print_arg_error(TOO_MUCH_ARG);
		print_help();
		return -1;
	}
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

void print_arg_error(int error) {
	if (error == WRONG_ARG) {
		printf(BLACKF RED BOLD "\t       WRONG ARGUMENT\n\n" DEFAULT);
	} else if (error == NO_ARG) {
		printf(BLACKF RED BOLD "\t       NO ARGUMENTS\n\n" DEFAULT);
	} else if (error == TOO_MUCH_ARG) {
		printf(BLACKF RED BOLD "\t    TOO MUCH ARGUMENTS\n\n" DEFAULT);
	}
}
