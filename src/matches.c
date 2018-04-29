#include <string.h>
#include <stdlib.h>
#include "matches.h"
#include <stdio.h>

int correct_match (int value){
	if (value > 10 || value < 1){
		printf("Value is not correct\n");
		return 1;
	}
	
	return 0;
}	


