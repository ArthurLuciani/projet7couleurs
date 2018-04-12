/* Template of the 7 wonders of the world of the 7 colors assigment. */

#include <stdio.h>     /* printf */
#include <time.h> 
#include <stdlib.h>
#include <unistd.h> 
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
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros
char temp_board[BOARD_SIZE * BOARD_SIZE];

char rand_a_b(char a, char b)
{
    return rand()%(b-a) +a;
}

/** Retrieves the color of a given board cell */
char get_cell(char* board, int x, int y)
{
    return board[y * BOARD_SIZE + x];
}

/** Changes the color of a given board cell */
void set_cell(char* board, int x, int y, char color)
{
    board[y * BOARD_SIZE + x] = color;
<<<<<<< HEAD
}

int recursive_update (int position_x, int position_y, char board[], char player, char color)
{
    // transforme les cases de manièe récursive (pot de peinture)
    set_cell(board, position_x,position_y,player);
    int nb_changement = 1;
	if ((position_x-1)>=0)
	{
		if (get_cell(board, position_x-1,position_y)==color)
		{
			nb_changement += recursive_update(position_x-1,position_y,board,player,color);
		}
	}
	if ((position_x+1)< BOARD_SIZE)
	{
		if (get_cell(board, position_x+1,position_y)==color)
		{
			nb_changement += recursive_update(position_x+1,position_y,board,player,color);
		}
	}
	if ((position_y-1)>=0)
    {
        if (get_cell(board, position_x,position_y-1)==color)
        {
            nb_changement += recursive_update(position_x,position_y-1,board,player,color);
        }
    }
	if ((position_y+1)<BOARD_SIZE)
    {
        if (get_cell(board, position_x,position_y+1)==color)
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
			if (get_cell(board,i,j)== color)
			{
                if ((i-1)>=0)
                {
                    if (get_cell(board,i-1,j)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }
                if ((i+1)< BOARD_SIZE)
                {
                    if (get_cell(board,i+1,j)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }
				if ((j-1)>=0)
                {
                    if (get_cell(board,i,j-1)==player)
                    {
                        nb_changement += recursive_update(i,j,board,player,color);
                        continue;
                    }
                }
                if ((j+1)<BOARD_SIZE)
                {
                    if (get_cell(board,i,j+1)==player)
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


//check par couleur
/*void colorcounterfct(int x, int y, int colorcounter[])
{
    switch(get_cell(int x, int y))

        case A: colorcounter[0]+=1;
            break;

        case B: colorcounter[1]+=1;
            break;

        case C: colorcounter[2]+=1;
            break;

        case D: colorcounter[3]+=1;
            break;

        case E: colorcounter[4]+=1;
            break;

        case F: colorcounter[5]+=1;
            break;

        case G: colorcounter[6]+=1;
            break;
}*/

char choiceglouton(char board[], char player)
{
    int colorcounter[7]={0,0,0,0,0,0,0};
    int colornb=0;
    char chosencolor='A';


    for(int k=0; k<6; k++) //chaque couleur
    {
        for(int i=0; i<BOARD_SIZE*BOARD_SIZE;i++)
        {
            temp_board[i]=board[i];
        }

        /*old
        copie de board_update_recu
        int nb_changement=0; remplace par colorcounter
        remplacer board par temp_board
        remplacer color par chosencolor*/

        colorcounter[k]+=board_update_recu(temp_board[], player, chosencolor)

        chosencolor+=1;
    }
    chosencolor='A';
    colornb=colorcounter[0];

    for(int i=1;i<6;i++)
    {
        if (colorcounter[i]>colornb)
        {
            colorcounter[i]=colornb;
            chosencolor='A'+i;
        }
    }
    return chosencolor;
}

char choicerandok(char board[], char player)
{
    int colorcounter[7]={0,0,0,0,0,0,0};
    int colornb=0;
    char chosencolor='A';

    for(int k=0; k<6; k++) //chaque couleur
    {
        for(int i=0; i<BOARD_SIZE*BOARD_SIZE;i++)
        {
            temp_board[i]=board[i];
        }

        //get_perimeter_size copie modifiee
        //perimeter = colorcounter[k]
        //remplacer board par temp_board
        //remplacer color par chosencolor

        for (int i=0; i<BOARD_SIZE; i++)
        {
            for (int j=0; j<BOARD_SIZE; j++)
            {
                if (get_cell(temp_board,i,j)== player)
                {
                    if ((i-1)>=0)
                    {
                        if (get_cell(temp_board,i-1,j)==chosencolor)
                        {
                            colorcounter[k] = 1;
                            set_cell(temp_board, i-1, j, '0');
                        }
                    }
                    if ((i+1)< BOARD_SIZE)
                    {
                        if (get_cell(temp_board,i+1,j)==chosencolor)
                        {
                            colorcounter[k] = 1;
                            set_cell(temp_board, i+1, j, '0');
                        }
                    }
                    if ((j-1)>=0)
                    {
                        if (get_cell(temp_board,i,j-1)==chosencolor)
                        {
                            colorcounter[k] = 1;
                            set_cell(temp_board, i, j-1, '0');
                        }
                    }
                    if ((j+1)<BOARD_SIZE)
                    {
                        if (get_cell(temp_board,i,j+1)==chosencolor)
                        {
                            colorcounter[k] = 1;
                            set_cell(temp_board, i, j+1, '0');
                        }
                    }
                }
            }
        }
        chosencolor+=1;
    }

    do
    {
        chosencolor=rand_a_b('A', 'G'+1);
    }
    while(colorcounter[chosencolor-'A']==0)

    return chosencolor;
}

/*old début glouton
char choiceia3(int player, int updatedcells[], int updatedcellssize, int colorcounter[])
{
    // /!\ soucis double check si profils d'escaliers
    int cell;
    int x,y;
    int colornb=0;
    char chosencolor='A';

    //boucle par case mise à jour
    for(int i=0; i<updatedcells;i++)
    {
        //test case dessous
        if((updatedcells[i])<(BOARD_SIZE*(BOARD_SIZE-1)))
        {
            ++y;
            colorcounterfct(x, y, colorcounter[]);
            --y;
        }
        //test case desssus
        if((updatedcells[i])>BOARD_SIZE)
        {
            --y;
            colorcounterfct(x, y, colorcounter[]);
            ++y;
        }
        //test case droite
        if((updatedcells[i]%BOARD_SIZE)>0)
        {
            ++x;
            colorcounterfct(x, y, colorcounter[]);
            --x;
        }
        //test case gauche
        if(updatedcells[i]%BOARD_SIZE<9)
        {
            --x;
            colorcounterfct(x, y, colorcounter[]);
            ++x;
        }
    }

    //non récursif, choix IA gloutonne et normale
    for(int i=1;i<6;i++)
    {
        if (colorcounter[i]>colornb)
        {
            colorcounter[i]=colornb;
            chosencolor='A'+i;
        }
    }
    colorcounter[chosencolor-'A']=0;

    return chosencolor;
}

//incrémenter les compteurs séparément*/

=======
}

void generate_aleat_board(char* board)
{
    for (int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
    {
        char nb = rand_a_b('A', 'G'+1);
        board[i] = nb;
    }
    set_cell(board, 0, BOARD_SIZE-1, P1_COLOR);
    set_cell(board, BOARD_SIZE-1, 0, P2_COLOR);
}

char colorselect(char* board)
{
    // joueur humain
    char color;
    do
    {
        printf("Selectionnez une couleur : ");
        scanf("%c", &color);
    }while(color < 'A' || color > 'G');
    return color;
}
>>>>>>> 0d2021e1d25dbe981a6659fed392f4bbed0b4e15

char alea_computer(char* board)
{
    // joueur aleatoire
    return rand_a_b('A', 'G'+1);
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
<<<<<<< HEAD
=======

int recursive_update (int position_x, int position_y, char* board, char player, char color, int nb_changement)
{
    // transforme les cases de manièe récursive (pot de peinture)
    set_cell(board, position_x,position_y,player);
    int nb_changement = 1;
	if ((position_x-1)>=0) 
	{
		if (get_cell(position_x-1,position_y)==color)
		{
			set_cell(position_x-1,position_y,player);
			nb_changement = recursive_update(position_x-1,position_y,board,player,color,nb_changement)+1;
		}
	}
	if ((position_x+1)< BOARD_SIZE)
	{
		if (get_cell(position_x+1,position_y)==color)
		{
			set_cell(position_x+1,position_y,player);
			nb_changement = recursive_update(position_x+1,position_y,board,player,color,nb_changement)+1;
		}
	}
	if ((position_y-1)>=0)
		{
			if (get_cell(position_x,position_y-1)==color)
			{
				set_cell(position_x,position_y-1,player);
				nb_changement = recursive_update(position_x,position_y-1,board,player,color,nb_changement)+1;
			}
		}
	if ((position_y+1)<BOARD_SIZE)
		{
			if (get_cell(position_x,position_y+1)==color)
			{
				set_cell(position_x,position_y+1,player);
				nb_changement = recursive_update(position_x,position_y-1,board,player,color,nb_changement)+1;
			}
		}
	return nb_changement;
}


int board_update_recu(char* board, char player, char color)
{
    // recherche les cases de la couleur color proches du territoire du joueur
	int nb_changement=0;
	for (int i=0; i<BOARD_SIZE;i++)
	{
		for (int j=0; j<BOARD_SIZE;j++)
		{
			if (get_cell(i,j)== color)
			{
				if ((i-1)>=0)
				{
					if (get_cell(i-1,j)==player)
					{
						nb_changement = recursive_update(i,j,board,player,color,0);
					}
				}
                if ((i+1)< BOARD_SIZE)
                {
                    if (get_cell(i+1,j)==player)
                    {
                        nb_changement = recursive_update(i,j,board,player,color,0);
                    }
                }
                if ((j-1)>=0)
                {
                    if (get_cell(i,j-1)==player)
                    {
                        nb_changement = recursive_update(i,j,board,player,color,0);
                    }
                }
                if ((j+1)<BOARD_SIZE)
                {
                    if (get_cell(i,j-1)==player)
                    {
                        nb_changement = recursive_update(i,j,board,player,color,0);
                    }
                }
			}
		}
	}

    return nb_changement;
}

int main(void)
{
    srand(time(NULL));
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");
    generate_aleat_board(board);
    print_board(board);

    int victory = 0;
    int count1 = 1;
    int count2 = 1;
    char color;
    /*char (*players_tab[2])(char*);
    select_players(players_tab);*/
    int k = 0;
    while (victory==0 && k<40)
    {
        k++;
		color=hegemonique(board, P1_COLOR);
		printf("_%c_ \n",color);
		count1 += board_update_recu(board, P1_COLOR, color);
		print_board(board);
		printf("le nombre de case est %d \n",count1);
		if (count1>(BOARD_SIZE*BOARD_SIZE/2))
		{
			victory=1;
		}

		color = hegemonique(board, P2_COLOR);
        printf("_%c_ \n",color);
		count2 += board_update_recu(board, P2_COLOR, color);
		print_board(board);
		printf("le nombre de case est %d \n",count2);
		if (count2>(BOARD_SIZE*BOARD_SIZE/2))
		{
			victory=1;
		}
        //sleep(1);
    }

    return 0; // Everything went well
}

void select_players(void* players_tab);
{
    //modifie le tableau des joueurs
    //players_tab sera alors un tableau de pointeus vers fonction
    printf("Selectionnez les joueurs\n1 : humain\n2 : aleatoire\n3 : aleatoire1+\n4 : glouton\n5 : hegemonique\n");
    printf("Joueur1 : ")
    char j1;
    scanf("%d",%j1);
    printf("Joueur2 : ")
    char j2;
    scanf("%d",%j1);
    for(int i = 0; i<2; i++)
    {
        switch(j1)
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
            players_select[i] = hegemonique;
            break;
            
        default :
            players_tab[i] = colorselect;
            break;
        }
    }
    return players_tab;
}
*/

>>>>>>> 0d2021e1d25dbe981a6659fed392f4bbed0b4e15

/** Program entry point */
int main(void)
{
    srand(time(NULL));
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");
    generate_aleat_board(board);
    print_board(board);

    int victory = 0;
    int count1 = 1;
    int count2 = 1;
    char color;
    /*char (*players_tab[2])(char*);
    select_players(players_tab);*/
    int k = 0;
    while (victory==0 && k<40)
    {
        k++;
		color=hegemonique(board, P1_COLOR);
		printf("_%c_ \n",color);
		count1 += board_update_recu(board, P1_COLOR, color);
		print_board(board);
		printf("le nombre de case est %d \n",count1);
		if (count1>(BOARD_SIZE*BOARD_SIZE/2))
		{
			victory=1;
		}

		color = hegemonique(board, P2_COLOR);
        printf("_%c_ \n",color);
		count2 += board_update_recu(board, P2_COLOR, color);
		print_board(board);
		printf("le nombre de case est %d \n",count2);
		if (count2>(BOARD_SIZE*BOARD_SIZE/2))
		{
			victory=1;
		}
        //sleep(1);
    }

    return 0; // Everything went well
}

int mainalter(void)
{
    //main alternatif : simulation de 100 parties
    srand(time(NULL));
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");

    int victory1 = 0;
    int victory2 = 0;



    for (int i=0;i<100;i++)
    {
        generate_aleat_board(board);
        print_board(board);

        int victory = 0;
        int count1 = 1;
        int count2 = 1;
        char color;
        /*char (*players_tab[2])(char*);
        select_players(players_tab);*/
        int k = 0;

        while (k<40)
        {
            k++;
            printf("Tour %d J1 :\n",k);
            //
            color=hegemonique(board, P1_COLOR);
            //
            printf("_%c_ \n",color);
            count1 += board_update_recu(board, P1_COLOR, color);
            print_board(board);
            printf("le nombre de case est %d \n",count1);
            if (count1>(BOARD_SIZE*BOARD_SIZE/2))
            {
                victory1+=1;
                break;
            }

            printf("Tour %d J2 :\n",k);
            //
            color = hegemonique(board, P2_COLOR);
            //
            printf("_%c_ \n",color);
            count2 += board_update_recu(board, P2_COLOR, color);
            print_board(board);
            printf("le nombre de case est %d \n",count2);
            if (count2>(BOARD_SIZE*BOARD_SIZE/2))
            {
                victory2+=1;
                break;
            }
            //sleep(1);
        }
    }

    printf("Victoires du joueur 1 : %d\nVictoires du joueur 2 : %d\n", victory1, victory2);
    sleep(5);

    return 0; // Everything went well
}

