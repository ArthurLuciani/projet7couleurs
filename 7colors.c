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
// -------- Prototype des fonctions ------------------------------------
/**
 **************** Fonction générales************************************
char rand_a_b(char a, char b) 
* renvoit un carctère compris entre a (inclu) et b (exclu)

char get_cell(char* board, int x, int y)
* renvoit la couelur se trouvant à la position x,y

void set_cell(char* board, int x, int y, char color)
* change la couleur se trouvant à la position x,y

void generate_aleat_board(char* board)
*  change les couleurs aléatoirement du tableau en entrée, et met les couleurs des joueurs dans les coins
*  utilise BOARD_SIZE qui doit être accessible

void print_board(char* board)
* affiche le tableau en entrée

int board_update_recu(char* board, char player, char color)
* actualise le tableau en entrée en fonction du joueur et de la couleur jouée, renvoit le nombre de case modifiée

int recursive_update (int position_x, int position_y, char* board, char player, char color)
* modifie la couleur des cases adjacentes de la case x,y qui sont de la bonne couleur

int get_perimeter_size(char* board, char player)
* retourne le nombre de case qui forme le périmètre du joueur
* utilise la couleur des joueurs (qui doivent être accessible)



******************************Les joueurs*******************************

int selection_player ()
* permet de selectionner un type de joueur


char colorselect(char* board, char player)
* permet à un joueur huamain de sélectionner une couleur

char alea_computer(char* board, char player)
* Renvoit le choix du joueur aléatoire classique

char hegemonique(char* board, char player)
* renvoit le choix du joueur hégémonique





























*/
//------------------ Programme -----------------------------------------






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



/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */
void print_board(char* board)
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", get_cell(board, i, j));
        }
        printf("\n");
    }
}

int recursive_update (int position_x, int position_y, char* board, char player, char color)
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

int get_perimeter_size(char* board, char player)
{
    int perimeter = 0;
	for (int i=0; i<BOARD_SIZE; i++)
	{
		for (int j=0; j<BOARD_SIZE; j++)
		{
			if (get_cell(board,i,j)== player)
			{
                if ((i-1)>=0) 
                {
                    if (get_cell(board,i-1,j)!=P1_COLOR &&
                        get_cell(board,i-1,j)!=P2_COLOR &&
                        get_cell(board,i-1,j)!= '0')
                    {
                        perimeter += 1;
                        set_cell(board, i-1, j, '0');
                    }
                }
                if ((i+1)< BOARD_SIZE) 
                {
                    if (get_cell(board,i+1,j)!=P1_COLOR &&
                        get_cell(board,i+1,j)!=P2_COLOR && 
                        get_cell(board,i+1,j)!= '0')
                    {
                        perimeter += 1;
                        set_cell(board, i+1, j, '0');
                    }
                }
				if ((j-1)>=0)  
                {
                    if (get_cell(board,i,j-1)!=P1_COLOR &&
                        get_cell(board,i,j-1)!=P2_COLOR && 
                        get_cell(board,i,j-1)!= '0')
                    {
                        perimeter += 1;
                        set_cell(board, i, j-1, '0');
                    }
                }
                if ((j+1)<BOARD_SIZE)
                {
                    if (get_cell(board,i,j+1)!=P1_COLOR &&
                        get_cell(board,i,j+1)!=P2_COLOR && 
                        get_cell(board,i,j+1)!= '0')
                    {
                        perimeter += 1;
                        set_cell(board, i, j+1, '0');
                    }
                }              
            }
        }
    }
    return perimeter; 
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

// ------------ Les joueurs --------------------------------------------

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
    char best_color = alea_computer(board, player);// couleur par defaut
    int perimeter = 0;
    printf("\n---------------test----------------\n");
    //------char temp_board[BOARD_SIZE * BOARD_SIZE];
    for(char color = 'A'; color <= 'G'; color++)
    {
        // on crée un plateau temporaire de test
        //------printf("\n----color : %c ------\n", color);
        for (int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
        {
            temp_board[i] = board[i];
        }
        board_update_recu(temp_board, player, color);
        // detection du perimetre
        perimeter = get_perimeter_size(temp_board, player);
        if (perimeter > best_perimeter)
        {
            best_perimeter = perimeter;
            best_color = color;
            //print_board(temp_board);
        }
    }
    // print_board(temp_board);
    printf("\nLa meilleur couleur pour %c est %c pour un perimetre de %d\n",player, best_color, best_perimeter);
    return best_color;
}

int selection_player ()
{
	int strategie_joueur=1;
	do 
	{
		printf("Selectioner le type de joueur :");
		printf("\n");
		printf("1=humain, 2=aleatoire, 3=aleatoire+, 4=glouton, 5=glouton_carre, 6=hegemonique");
		printf("\n");
		scanf("%d",&strategie_joueur);
		printf("\n");

	}while(strategie_joueur>6 || strategie_joueur <1);
	return strategie_joueur;
}









/** Program entry point */
int main(void)
{
    srand(time(NULL));
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");
	int victory = 0;
    int count1 = 1;
    int count2 = 1;
    char color;   
	int strategie_joueur1=1;
	int strategie_joueur2=1;
	strategie_joueur1=selection_player();
	strategie_joueur2=selection_player();
    generate_aleat_board(board);
    print_board(board);
    char (*pointeur_sur_fonction_joueur1)(char*,char);
    char (*pointeur_sur_fonction_joueur2)(char*,char);
    switch(strategie_joueur1)
        {
        case 1 :
            pointeur_sur_fonction_joueur1 = colorselect;
            break;
            
        case 2 :
            pointeur_sur_fonction_joueur1 = alea_computer;
            break;
            
        /*case 3 :
			pointeur_sur_fonction_joueur1 = alea_computer+;
			break
            
        case 4 :
            pointeur_sur_fonction_joueur1 = opti1;
            break;
            
        case 5 :
            pointeur_sur_fonction_joueur1 = opti2;
            break;*/
            
        case 6 :
            pointeur_sur_fonction_joueur1 = hegemonique;
            break;
            
        default :
            pointeur_sur_fonction_joueur1 = colorselect;
            break;
        }
    
    switch(strategie_joueur2)
        {
        case 1 :
            pointeur_sur_fonction_joueur2 = colorselect;
            break;
            
        case 2 :
            pointeur_sur_fonction_joueur2 = alea_computer;
            break;
            
        /*case 3 :
			pointeur_sur_fonction_joueur2 = alea_computer+;
			break
            
        case 4 :
            pointeur_sur_fonction_joueur2 = opti1;
            break;
            
        case 5 :
            pointeur_sur_fonction_joueur2 = opti2;
            break;*/
            
        case 6 :
            pointeur_sur_fonction_joueur2 = hegemonique;
            break;
            
        default :
            pointeur_sur_fonction_joueur2 = colorselect;
            break;
        }
    
    
    while (victory==0)
    {
		color=(*pointeur_sur_fonction_joueur1)(board,P1_COLOR);
		printf("_%c_ \n",color);
		count1 += board_update_recu(board, P1_COLOR, color);
		print_board(board);
		printf("le nombre de case est %d \n",count1);
		if (count1>(BOARD_SIZE*BOARD_SIZE/2))
		{ 
			victory=1;
		}
		color=(*pointeur_sur_fonction_joueur2)(board,P2_COLOR);
		printf("_%c_ \n",color);
		count2 += board_update_recu(board, P2_COLOR, color);
		print_board(board);
		printf("le nombre de case est %d \n",count2);
		if (count2>(BOARD_SIZE*BOARD_SIZE/2))
		{ 
			victory=1;
		}
	}
    
    /*char (*players_tab[2])(char*);
    select_players(players_tab);*/
    /*int k = 0;
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
    */
    return 0; // Everything went well
}
