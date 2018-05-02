#include <stdio.h>
#include "bulls.h"

int main()
{

	while (1) {
		char * num = enter_number("SlowKing");

		if (num != NULL) {
			if (!check_number(num)) {
				printf("%s\n", num);
				break;
			}
		} else {
			continue;
		}
	}

	return 0;
}
