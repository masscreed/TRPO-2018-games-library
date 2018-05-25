#ifndef MATCHES_H
#define MATCHES_H

#define MATCHES_LEFT (3)
#define TAKE_MATCH (2)
#define YOUR_TURN (1)
#define TOO_LARGE_HEAP (-1)
#define MANY_LETTERS (-2)

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
