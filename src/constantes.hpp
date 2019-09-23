#ifndef CONSTATNTES_H
#define CONSTATNTES_H
/* We want a 30x30 board game by default */
#define BOARD_SIZE 30
#define P1_COLOR '.'
#define P2_COLOR '*'

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros
char temp_board[BOARD_SIZE * BOARD_SIZE];
int changement = 0;
int DEBUG_MODE;

#endif