#ifndef MATCHES_H
#define MATCHES_H

int ask_nickname(char *player, int index);
char *enter_nickname(char *player);
int check_nickname(char *player);
int check_match(char *value);
void matches_game();
void flush_input_for_match();
char *enter_matches();
int check_heap (int *heap, int turn);
void flag_errors (int flag);
void win_show(int win, char *player);

#endif
