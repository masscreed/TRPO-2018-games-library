#ifndef MATCHES_H
#define MATCHES_H

int ask_nicknames(char *player1, char *player2);
char *enter_nickname(char *player);
int check_nickname(char *player);
char *correct_match(char *value);
int matches_game(char *player1, char *player2);
void flush_input_for_match();
char *enter_matches();

#endif
