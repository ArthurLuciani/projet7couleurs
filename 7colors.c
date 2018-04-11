/* Template of the 7 wonders of the world of the 7 colors assigment. */

#include <stdio.h>     /* printf */
#include <time.h> 
#include <stdlib.h>
/* We want a 30x30 board game by default */
#define BOARD_SIZE 30

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros

char rand_a_b(char a, char b)
{
    return rand()%(b-a) +a;
}

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

void generate_aleat_board(char* board)
{
    for (int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
    {
        char nb = rand_a_b('A', 'G'+1);
        board[i] = nb;
    }
    set_cell(0, BOARD_SIZE-1, '.');
    set_cell(BOARD_SIZE-1, 0, '^');
}

int get_perimeter_size(char* board, char player):
{
      int perimeter = 0;
      for()  
}



char colorselect(char* board, char player)
{
    // joueur humain
    char color;
    do
    {
        printf("Selectionnez une couleur : ");
        printf("\n");
        scanf("%c", &color);
    }while(color < 'A' || color > 'G');
    return color;
}

char alea_computer(char* board, char player)
{
    // joueur aleatoire
    return rand_a_b('A', 'G'+1);
}

char hegemonique(char* board, char player)
{
    // implémentation du joueur hegemonique (augmentation du périmètre)
    int best_perimeter = 0;
    char best_color = 'A';// couleur par defaut
    for(char color = 'A'; color <= 'G'; color++)
    {
        // on crée un plateau temporaire de test
        char* temp_board;
        for (int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
        {
            temp_board[i] = board[i];
        }
        board_update_recu(temp_board, player, color);
        // detection du perimetre
        int perimeter = get_perimeter_size(temp_board, player);
        if (perimeter > best_perimeter)
        {
            best_perimeter = perimeter;
            best_color = color;
        }
    }
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

int recursive_update (int position_x, int position_y, char* board, char player, char color)
{
    // transforme les cases de manièe récursive (pot de peinture)
    set_cell(position_x,position_y,player);
    int nb_changement = 1;
	if ((position_x-1)>=0) 
	{
		if (get_cell(position_x-1,position_y)==color)
		{
			nb_changement += recursive_update(position_x-1,position_y,board,player,color);
		}
	}
	if ((position_x+1)< BOARD_SIZE) 
	{
		if (get_cell(position_x+1,position_y)==color)
		{
			nb_changement += recursive_update(position_x+1,position_y,board,player,color);
		}
	}
	if ((position_y-1)>=0)  
    {
        if (get_cell(position_x,position_y-1)==color)
        {
            nb_changement += recursive_update(position_x,position_y-1,board,player,color);
        }
    }
	if ((position_y+1)<BOARD_SIZE)
    {
        if (get_cell(position_x,position_y+1)==color)
        {
            nb_changement += recursive_update(position_x,position_y-1,board,player,color);
        }
    }
	return nb_changement;
}


int board_update_recu(char* board, char player, char color)
{
    // recherche les cases de la couleur color proches du territoire du joueur
	int nb_changement=0;
	for (int i=0; i<BOARD_SIZE; i++)
	{
		for (int j=0; j<BOARD_SIZE; j++)
		{
			if (get_cell(i,j)== color)
			{
                if ((i-1)>=0) 
                {
                    if (get_cell(i-1,j)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }
                if ((i+1)< BOARD_SIZE) 
                {
                    if (get_cell(i+1,j)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }
				if ((j-1)>=0)  
                {
                    if (get_cell(i,j-1)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }
                if ((j+1)<BOARD_SIZE)
                {
                    if (get_cell(i,j+1)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }              
            }
        }
    }
	return nb_changement;
}

/*
char *(*select_players(void))(char*)
{
    //modifie le tableau des joueurs
    //players_tab sera alors un tableau de pointeus vers fonction
    char (*players_tab[2])(char*);
    printf("Sélectionnez les joueurs\n1 : humain\n2 : aleatoire\n3 : opti1\n4 : opti2\n5 : hegemonique\n");
    printf("Joueur1 : ");
    int j[2];
    scanf("%d",&j[0]);
    printf("Joueur2 : ");
    scanf("%d",&j[1]);
    for(int i = 0; i<2; i++)
    {
        switch(j[i])
        {
        case 1 :
            players_tab[i] = colorselect;
            break;
        case 2 :
            players_tab[i] = alea_computer;
            break;
            
        case 3 :
            players_tab[i] = opti1;
            break;
        case 4 :
            players_tab[i] = opti2;
            break;
        case 5 :
            palyers_select[i] = hegemonique;
            break;
            
        default :
            palyers_tab[i] = colorselect;
            break;
        }
    }
    return players_tab;
}
*/

/** Program entry point */
int main(void)
{
    srand(time(NULL));
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");
    generate_aleat_board(board);
    print_board();

    int victory = 0;
    int count1 = 1;
    int count2 = 1;
    char color;
    /*char (*players_tab[2])(char*);
    select_players(players_tab);*/
    
    while (victory==0)
    {
		color=colorselect(board);
		printf("_%c_ \n",color);
		count1=board_update_recu(board,'.',color)+count1;
		print_board();
		printf("le nombre de case est %d \n",count1);
		if (count1>45)
		{ 
			victory=1;
		}
    
		color=colorselect(board);
        printf("_%c_ \n",color);
		count2=board_update_recu(board,'^',color)+count2;
		print_board();
		printf("le nombre de case est %d \n",count2);
		if (count2>45)
		{ 
			victory=1;
		}
    }
    
    return 0; // Everything went well
}
