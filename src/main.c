#include <stdio.h>
#include "bulls.h"

int main()
{
	char * num;
	while (1) {
		num = enter_number("SlowKing");

		if (num != NULL) {
			if (!check_number(num)) {
				break;
			} else {
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
