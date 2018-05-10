#ifndef GAMES_BULLS_H
#define GAMES_BULLS_H

int first_player ();
char *enter_number(char *player);
int check_number(char *number);
int guessing(char *player, char *number);
void print_bulls_cows(int bullcow);
void print_error(int error);

void flush_input();


#endif //GAMES_BULLS_H
