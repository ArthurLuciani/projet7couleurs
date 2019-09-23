#ifndef COLORS_H
#define COLORS_H
/* Template of the 7 wonders of the world of the 7 colors assigment. */

#include <stdio.h>     /* printf */
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>



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


/* renvoit un carctère compris entre a (inclu) et b (exclu)
 * @param a : le premier caractère (borne inférieure)
 * @param b : le deuxième caractère (borne supérieure)
 * @return : un caractère
 */
char rand_a_b(char a, char b);


//renvoit la couelur se trouvant à la position x,y
char get_cell(char* board, int x, int y);


//change la couleur se trouvant à la position x,y
void set_cell(char* board, int x, int y, char color);


// change les couleurs aléatoirement du tableau en entrée, et met les couleurs des joueurs dans les coins
// utilise BOARD_SIZE qui doit être accessible
void generate_aleat_board(char* board);


// affiche le tableau en entrée
void print_board(char* board);


// actualise le tableau en entrée en fonction du joueur et de la couleur jouée, renvoit le nombre de case modifiée
int board_update_recu(char* board, char player, char color);


// modifie la couleur des cases adjacentes de la case x,y qui sont de la bonne couleur
int recursive_update (int position_x, int position_y, char* board, char player, char color);


// retourne le nombre de case qui forme le périmètre du joueur
// utilise la couleur des joueurs (qui doivent être accessible)
int get_perimeter_size(char* board, char player);


// renvoit 1 si la couleur est présente sur les frontières du joueur
// renvoit 0 sinon
int bordercolorpresence(char chosencolor, char* board, char player);


// renvoit le nombre de changement maximum pour (glouton_count) coups
int glouton_recu_count(char board[], char player, int glouton_count);


//******************************Les joueurs*******************************


// permet de selectionner un type de joueur
int selection_player();


// permet à un joueur huamain de sélectionner une couleur
char colorselect(char* board, char player);


// Renvoit le choix du joueur aléatoire classique
char alea_computer(char* board, char player);


// renvoit le choix du joueur aléatoire amélioré
char alea_computer_ameliore(char* board, char player);


// renvoi le choix du joueur glouton
char glouton(char* board, char player);


// renvoi le choix du joueur glouton prevoyant
char glouton_2(char board[], char player);


// renvoi le choix du joueur glouton prevoyant
char glouton_n(char board[], char player);


// renvoit le choix du joueur hégémonique
char hegemonique(char* board, char player);


// renvoit le choix du joueur hybride
char hybride (char* board, char player);

#endif