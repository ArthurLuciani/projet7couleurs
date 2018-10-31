/* Template of the 7 wonders of the world of the 7 colors assigment. */

#include <stdio.h>     /* printf */
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/* We want a 30x30 board game by default */
#define BOARD_SIZE 30
#define P1_COLOR '.'
#define P2_COLOR '*'

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
// -------- Prototype des fonctions ------------------------------------
/**
 **************** Fonction générales************************************
*/
char rand_a_b(char a, char b);
//renvoit un carctère compris entre a (inclu) et b (exclu)

char get_cell(char* board, int x, int y);
//renvoit la couelur se trouvant à la position x,y

void set_cell(char* board, int x, int y, char color);
//change la couleur se trouvant à la position x,y

void generate_aleat_board(char* board);
// change les couleurs aléatoirement du tableau en entrée, et met les couleurs des joueurs dans les coins
// utilise BOARD_SIZE qui doit être accessible

void print_board(char* board);
// affiche le tableau en entrée

int board_update_recu(char* board, char player, char color);
// actualise le tableau en entrée en fonction du joueur et de la couleur jouée, renvoit le nombre de case modifiée

int recursive_update (int position_x, int position_y, char* board, char player, char color);
// modifie la couleur des cases adjacentes de la case x,y qui sont de la bonne couleur

int get_perimeter_size(char* board, char player);
// retourne le nombre de case qui forme le périmètre du joueur
// utilise la couleur des joueurs (qui doivent être accessible)

int bordercolorpresence(char chosencolor, char* board, char player);
// renvoit 1 si la couleur est présente sur les frontières du joueur
// renvoit 0 sinon

int glouton_recu_count(char board[], char player, int glouton_count);
// renvoit le nombre de changement maximum pour (glouton_count) coups

//******************************Les joueurs*******************************

int selection_player ();
// permet de selectionner un type de joueur


char colorselect(char* board, char player);
// permet à un joueur huamain de sélectionner une couleur

char alea_computer(char* board, char player);
// Renvoit le choix du joueur aléatoire classique

char alea_computer_ameliore(char* board, char player);
// renvoit le choix du joueur aléatoire amélioré

char glouton(char* board, char player);
// renvoi le choix du joueur glouton

char glouton_2(char board[], char player);
// renvoi le choix du joueur glouton prevoyant

char glouton_n(char board[], char player);
// renvoi le choix du joueur glouton prevoyant

char hegemonique(char* board, char player);
// renvoit le choix du joueur hégémonique
char hybride (char* board, char player);
// renvoit le choix du joueur hybride


char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros
char temp_board[BOARD_SIZE * BOARD_SIZE];