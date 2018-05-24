#ifndef GAMES_BULLS_H
#define GAMES_BULLS_H

#define SMBL_IN_INPUT (-1)
#define NOT_4_DIGIT_LESS (-3)
#define DIGITS_REPEATS (-2)
#define NOT_4_DIGIT_MORE (-4)
#define NULL_ERROR (-5)


//Input functions
char *enter_number(char *player);

//Game logic functions
void bulls_game();
int first_player ();
char *create_player_num(char *player);
void turns_loop(char *player1, char *player2, char *p1_number, char *p2_number);
int make_turn (char *player, char *number);
int guessing(char *player, char *number);
void find_out_bull_cow(int *bulls, int *cows, int bullcow);

//Output functions
void print_error(int error);

void print_priority(char *player);
void print_turn(int turn);
void print_bulls_cows(int bullcow);
void print_draw(char *saved, char *second, char *sav_num, char *sec_num);
void print_win(char *winner, char *loser, char *win_num, char *l_num);
void print_player_and_num(char *player, char *number);
void print_creating();
void print_blank();
void print_last_chance(char *player1, char *player2);

//Additional functions
void flush_input();

//Input logic functions
int check_number(char *number);

#endif //GAMES_BULLS_H
