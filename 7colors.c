/* Template of the 7 wonders of the world of the 7 colors assigment. */

#include <stdio.h>     /* printf */

/* We want a 30x30 board game by default */
#define BOARD_SIZE 30

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros

/** Retrieves the color of a given board cell */
char get_cell(int x, int y)
{
    return board[y * BOARD_SIZE + x];
}

/** Changes the color of a given board cell */
void set_cell(int x, int y, char color)
{
    board[y * BOARD_SIZE + x] = color;
}

/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */
void print_board(void)
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c", get_cell(i, j));
        }
        printf("\n");
    }
}

int recursive_update (int position_x, int position_y char* board, char player, char color, int changement)
{
	for (int k=0, k<2;k++)
	{
		for (int l=0, l<2,l++)
		{
			if (((position_x-1+2*k)>=0) && ((position_x-1+2*k)< BOARD_SIZE) && ((position_y-1+2*l)>=0) && ((position_y-1+2*l)<BOARD_SIZE))
				if (get_cell(position_x-1+2*k,position_y-1+2*l)=color)
					{
						set_cell(position_x-1+2*k,position_y-1+2*l,player)
						changement=recursive_update(board,player,color, changement)+1;
					}
		}
	}
	return changement 
}


int board_update_recu(char* board, char player, char color)
{
	int nb_changement=0;
	for (int i=0; i<BOARD_SIZE;i++)
	{
		for (int j=0; j<BOARD_SIZE;j++)
		{
			if (get_cell(i,j)== color)
		
			{
				for (int k=0, k<2;k++)
				{
					for (int l=0, l<2,l++)
					{
						if (((i-1+2*k)>=0) && ((i-1+2*k)< BOARD_SIZE) && ((j-1+2*l)>=0) && ((j-1+2*l)<BOARD_SIZE))
						{
							if (get_cell(i-1+2*k,j-1+2*l)=player)
							{
							nb_changement = recursive_update(board,player,color,0);
							}
						}
					}
				}
			}
		}
	}
	
    return nb_changement;
}



/** Program entry point */
int main(void)
{
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");

    print_board();

    return 0; // Everything went well
}
