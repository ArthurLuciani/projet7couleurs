/* Proto of the 7 wonders of the world of the 7 colors assigment.*/

/** Retrieves the color of a given board cell */

void generate_aleat_board(char* board)
{
    ;
}

int board_update(char* board, char player, char color)
{
    //retourne le nombre de cases prises par le coup
    return;
}

//Q3 optionnelle
int board_update_recu(char* board, char player, char color)
{
    //retourne le nombre de cases prises par le coup (récu)
    return;
}

//Q4
char colorselect()
{
    return(color);
}

//Q5


char get_cell(int x, int y)
{
    ;
}

/** Changes the color of a given board cell */
void set_cell(int x, int y, char color)
{
    ;
}

/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */

char color_alea();

void print_board(void)
{
    ;
}


/** Program entry point */
int main(void)
{
    //init
    char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros
    int victory = 0;
    int count1 = 0;
    int count2 = 0;
    //choix
    //victory condition + boucle de jeu Q5 :
    while(!victory)...
}

/*
char* player1 = &colorselect

int player1 = 1,2,3
int player2 = 1,2,3

char a = 0;

joueurswitch[]

char alea_computer(char* board);

char (*player1)(char*);
player1 = &(selectcolor)

couleur = (*player1)(board)


player1()*/
