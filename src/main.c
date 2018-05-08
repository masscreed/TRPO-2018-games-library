#include <stdio.h>
#include "bulls.h"
#include "matches.h"
#include <string.h>

int main()
{
	char pl1[20], pl2[20];
	nicknames(pl1, pl2);
	char congr [] = {", You Won!!!! "};
	int win;
	win = matches_game(pl1, pl2);
	if (win == 1){
		strcat(pl1, congr);
		printf("%s", pl1);
	} else {
		strcat(pl2, congr);
		printf("%s", pl2);
	}


   return 0;
}
