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
void print_flag_errors (int flag);
void print_winnner(int win, char *player);
void print_ask_name(char *player, int index);
void print_over(int i);
void print_matches_turn(char *player, int i, int *matches);

#endif
