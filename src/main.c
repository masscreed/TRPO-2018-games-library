#include <stdio.h>
#include "bulls.h"
#include "matches.h"
#include <string.h>

int main()
{
	char * num;
	while (1) {
		num = enter_number("SlowKing");

		if (num != NULL) {
			int error = check_number(num);
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

	int bc = guessing("Lion", num);

	print_bulls_cows(bc);

	return 0;
}
