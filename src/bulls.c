#include <stdlib.h>
#include <time.h>
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
