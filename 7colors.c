#include "7colors.h"
#include "constantes.h"

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
    char c;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            c = get_cell(board, i, j);
            switch(c)
            {
                case 'A': printf(RED     "%c "   RESET, c); break;
                case 'B': printf(GREEN   "%c "   RESET, c); break;
                case 'C': printf(YELLOW  "%c "   RESET, c); break;
                case 'D': printf(BLUE    "%c "   RESET, c); break;
                case 'E': printf(MAGENTA "%c "   RESET, c); break;
                case 'F': printf(CYAN    "%c "   RESET, c); break;
                default: printf("%c ", c); break;
            }
            
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
            nb_changement += recursive_update(position_x,position_y+1,board,player,color);
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
	char tmp_board[BOARD_SIZE*BOARD_SIZE];
	for (int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		tmp_board[i] = board[i];
	}

  int perimeter = 0;
	for (int i=0; i<BOARD_SIZE; i++)
	{
		for (int j=0; j<BOARD_SIZE; j++)
		{
			if (get_cell(tmp_board,i,j)== player)
			{
                if ((i-1)>=0)
                {
                    if (get_cell(tmp_board,i-1,j)!=P1_COLOR &&
                        get_cell(tmp_board,i-1,j)!=P2_COLOR &&
                        get_cell(tmp_board,i-1,j)!= '0')
                    {
                        perimeter += 1;
                        set_cell(tmp_board, i-1, j, '0');
                    }
                }
                if ((i+1)< BOARD_SIZE)
                {
                    if (get_cell(tmp_board,i+1,j)!=P1_COLOR &&
                        get_cell(tmp_board,i+1,j)!=P2_COLOR && 
                        get_cell(tmp_board,i+1,j)!= '0')
                    {
                        perimeter += 1;
                        set_cell(tmp_board, i+1, j, '0');
                    }
                }
				if ((j-1)>=0)  
                {
                    if (get_cell(tmp_board,i,j-1)!=P1_COLOR &&
                        get_cell(tmp_board,i,j-1)!=P2_COLOR && 
                        get_cell(tmp_board,i,j-1)!= '0')
                    {
                        perimeter += 1;
                        set_cell(tmp_board, i, j-1, '0');
                    }
                }
                if ((j+1)<BOARD_SIZE)
                {
                    if (get_cell(tmp_board,i,j+1)!=P1_COLOR &&
                        get_cell(tmp_board,i,j+1)!=P2_COLOR && 
                        get_cell(tmp_board,i,j+1)!= '0')
                    {
                        perimeter += 1;
                        set_cell(tmp_board, i, j+1, '0');
                    }
                }
            }
        }
    }
    return perimeter;
}



int bordercolorpresence(char chosencolor, char* board, char player)
{
	int colorpresence=0;
	
	for (int i=0; i<BOARD_SIZE; i++)
	{
		for (int j=0; j<BOARD_SIZE; j++)
		{
			if (get_cell(board,i,j)== player)
			{
				if ((i-1)>=0)
				{
					if (get_cell(board,i-1,j)==chosencolor)
					{
						colorpresence = 1;
					}
				}
				if ((i+1)< BOARD_SIZE)
				{
					if (get_cell(board,i+1,j)==chosencolor)
					{
						colorpresence = 1;
					}
				}
				if ((j-1)>=0)
				{
					if (get_cell(board,i,j-1)==chosencolor)
					{
						colorpresence = 1;
					}
				}
				if ((j+1)<BOARD_SIZE)
				{
					if (get_cell(board,i,j+1)==chosencolor)
					{
						colorpresence = 1;
					}
				}
			}
		}
	}
	return colorpresence;
}
	

int glouton_recu_count(char* board, char player, int glouton_count)
{
    int colorcounter[7]={0,0,0,0,0,0,0};
    char chosencolor = 'A';
//    char temp_board_n[7][BOARD_SIZE * BOARD_SIZE];
    char temp_board_n[BOARD_SIZE * BOARD_SIZE];
    for(int k=0; k<7; k++) //chaque couleur
    {

        for(int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
        {
            temp_board_n[i] = board[i];
        }

        colorcounter[k] = board_update_recu(temp_board_n, player, chosencolor);

        if(glouton_count>1)
        {
            colorcounter[k] += glouton_recu_count(temp_board_n, player, glouton_count-1);
        }

        chosencolor++;
    }

    for(int i=1;i<7;i++)
    {
        if (colorcounter[0]<colorcounter[i])
        {
            colorcounter[0] = colorcounter[i];
        }
    }

    return colorcounter[0];
}



// ------------ Les joueurs --------------------------------------------


char colorselect(char* board, char player)
{
    // joueur humain
    char color;
    while(color < 'A' || color > 'G')
        {
        printf("Selectionnez une couleur : ");
        printf("\n");
        scanf("%c", &color);
       	}
    return color;
}

char alea_computer(char* board, char player)
{
    // joueur aleatoire
    return rand_a_b('A', 'G'+1);
}

char alea_computer_ameliore(char* board, char player)
{
	char chosencolor='P';
	do
    {
        chosencolor=rand_a_b('A', 'G'+1);
    }
    while(bordercolorpresence(chosencolor,board,player)==0);

    return chosencolor;
}


char glouton(char* board, char player)
{
    int colorcounter[7]={0,0,0,0,0,0,0};
    int colornb = 0;
    char chosencolor = 'A';


    for(int k=0; k<7; k++) //chaque couleur
    {
        for(int i=0; i<BOARD_SIZE*BOARD_SIZE;i++)
        {
            temp_board[i]=board[i];
        }

        colorcounter[k] += board_update_recu(temp_board, player, chosencolor);

        chosencolor+=1;
    }
    chosencolor='A';
    colornb = colorcounter[0];

    for(int i=1;i<7;i++)
    {
        if (colorcounter[i]>colornb)
        {
            colornb = colorcounter[i];
            chosencolor='A'+i;
        }
    }
    return chosencolor;
}



char glouton_2(char board[], char player)
{
    int colorcounter[7]={0,0,0,0,0,0,0};
    int colorcounter_2[7]={0,0,0,0,0,0};
    char temp_board[BOARD_SIZE * BOARD_SIZE];
    char temp_board_2[BOARD_SIZE * BOARD_SIZE];
	int chosencolor='A';
	
    for(int k=0; k<7; k++) //chaque couleur
    {
        for(int i=0; i<BOARD_SIZE*BOARD_SIZE;i++) // init tableau
        {
            temp_board[i]=board[i];
        }

        colorcounter[k]+=board_update_recu(temp_board, player, 'A'+k);

        for(char color = 'A'; color <= 'G'; color++)
		{
			for(int i=0; i<BOARD_SIZE*BOARD_SIZE;i++)
			{
				temp_board_2[i]=temp_board[i];
			}
			colorcounter_2[color-'A']=board_update_recu(temp_board_2, player, color);
		}
		for(int i=1;i<7;i++)
		{
			if (colorcounter_2[0]<colorcounter_2[i])
			{
				colorcounter_2[0]=colorcounter_2[i];
			}
		}
		colorcounter[k]+=colorcounter_2[0];
		
        for (int j=0; j<7;j++)
        {
			colorcounter_2[j]= 0;
		}
    }
       

    for(int i=1;i<7;i++)
    {
        if (colorcounter[0]<=colorcounter[i])
        {
            colorcounter[0]=colorcounter[i];
            chosencolor='A'+i;
        }
    }
    for(int i=0; i<BOARD_SIZE*BOARD_SIZE;i++) // init tableau
        {
            temp_board[i]=board[i];
        }
    if (board_update_recu (temp_board,player, chosencolor)==0)
    {
		chosencolor=glouton(board,player);
	}

    return(chosencolor);
}


char glouton_n(char* board, char player)
{
    int glouton_count=(2); // > 1
    int colorcounter[7]={0,0,0,0,0,0,0};
    char temp_board_n[BOARD_SIZE * BOARD_SIZE];
    char chosencolor = 'A';
    char best_color_yet = 'A';
    int best_change = 0;
    //debut recu
    for(int k=0; k<7; k++) //chaque couleur
    {
        for(int i=0; i < BOARD_SIZE*BOARD_SIZE; i++)
        {
            temp_board_n[i] = board[i];
        }
        colorcounter[k] += board_update_recu(temp_board_n, player, chosencolor);
        if (colorcounter[k] > best_change)
        {
            best_change = colorcounter[k];
            best_color_yet = 'A' + (char) k;
        }
        //printf("\n--- %d ---- %c ---\n", colorcounter[k], chosencolor);
        colorcounter[k] += glouton_recu_count(temp_board_n, player, glouton_count-1);

        chosencolor++;
    }
    //fin recu
    
    for(int i=1;i<7;i++)
    {
        if (colorcounter[i] > best_change)
        {
            best_change = colorcounter[i];
            best_color_yet = 'A' + (char) i;
        }
    }
    return best_color_yet;
}




char hegemonique(char* board, char player)
{
    // implementation du joueur hegemonique (augmentation du perimetre)


    int best_perimeter = get_perimeter_size(board, player);
    char best_color = glouton(board, player);// couleur par defaut

    int perimeter = 0;
    printf("\n---------------test----------------\n");
    //------char temp_board[BOARD_SIZE * BOARD_SIZE];
    for(char color = 'A'; color <= 'G'; color++)
    {
        // on cree un plateau temporaire de test
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




char hybride (char* board, char player)
{
	char color='A';
//	static int changement;
	int perimeter=get_perimeter_size(board, player);
	
	if (changement==1)
	{
		color=glouton_2(board,player);
	} else 	{
		color=hegemonique(board,player);
		if(get_perimeter_size(board, player)<=perimeter)
		{
			changement = 1;
		}
	}
	return color;
}







int selection_player()
{
    int strategie_joueur=0;
    while(strategie_joueur>7 || strategie_joueur <1)
	{
		printf("Selectioner le type de joueur :");
		printf("\n");
		printf("1=humain, 2=aleatoire, 3=aleatoire+, 4=glouton, 5=glouton_carre, 6=hegemonique, 7=hybride");
		printf("\n");
		scanf("%d",&strategie_joueur);
		printf("\n");
		
		if (strategie_joueur>7 || strategie_joueur <1)
		{
			while ((strategie_joueur=getchar()) != '\n' && strategie_joueur!= EOF) {}
		}

	}
	return strategie_joueur;
}


/** Program entry point */
int main(void)
{
	int again=1;
	while (again==1)
    {
		again=0;
		srand(time(NULL));
		printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
		   "*****************************************************\n\n"
		   "Current board state:\n");
		int victory = 0;
		int nb_parties=1;
		int nb_victoire_joueur1 = 0;
		int nb_victoire_joueur2 = 0;
		int count1 = 1;
		int count2 = 1;
		int vainqueur=0;
		char color;   
		int strategie_joueur1=1;
		int strategie_joueur2=1;
		strategie_joueur1=selection_player();
		strategie_joueur2=selection_player();
		
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
				
			case 3 :
				pointeur_sur_fonction_joueur1 = alea_computer_ameliore;
				break;
				
			case 4 :
				pointeur_sur_fonction_joueur1 = glouton;
				break;
				
		   case 5 :
				pointeur_sur_fonction_joueur1 = glouton_n;
				break;
				
			case 6 :
				pointeur_sur_fonction_joueur1 = hegemonique;
				break;
			case 7 :
				pointeur_sur_fonction_joueur2 = hegemonique;
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
				
			case 3 :
				pointeur_sur_fonction_joueur2 = alea_computer_ameliore;
				break;
				
			case 4 :
				pointeur_sur_fonction_joueur2 = glouton;
				break;
				
			case 5 :
				pointeur_sur_fonction_joueur2 = glouton_n;
				break;
				
			case 6 :
				pointeur_sur_fonction_joueur2 = hegemonique;
				break;
				
			case 7:
				pointeur_sur_fonction_joueur2 = hybride;
				break;
				
			default :
				pointeur_sur_fonction_joueur2 = colorselect;
				break;
			}
		
		printf("entrer le nombre de partie que vous voulez jouer\n");
		scanf("%d",&nb_parties);
		printf("\n");
		
		for (int i=0;i<nb_parties;i++)
		{
			victory=0;
			generate_aleat_board(board);
			count1 = 1;
			count2 = 1;
			changement = 0;
			while (victory==0)
			{
				printf("Joueur 1 rentrez la couleur que vous souhaitez jouer ");
				color=(*pointeur_sur_fonction_joueur1)(board,P1_COLOR);
				printf("_%c_ \n",color);
				count1 += board_update_recu(board, P1_COLOR, color);
				if (strategie_joueur1==1)
				{
					while ((color = getchar()) != '\n' && color!= EOF) {}
				}
				printf("l'occupation est de %d %% \n",(int)(count1*100/pow(BOARD_SIZE,2)));
				if (count1>=(BOARD_SIZE*BOARD_SIZE/2))
				{ 
					victory=1;
					nb_victoire_joueur1 +=1;
				}
				printf("Joueur 2 rentrez la couleur que vous souhaitez jouer ");
				color=(*pointeur_sur_fonction_joueur2)(board,P2_COLOR);
				printf("_%c_\n",color);
				count2 += board_update_recu(board, P2_COLOR, color);
				if (strategie_joueur2==1)
				{
					while ((color = getchar()) != '\n' && color!= EOF) {}
				}
                if (strategie_joueur1 == 1)
                {
                    print_board(board);
                }
				printf("l'occupation est de %d %% \n",(int)(count2*100/pow(BOARD_SIZE,2)));
				if (count2>=(BOARD_SIZE*BOARD_SIZE/2))
				{ 
					victory=1;
					nb_victoire_joueur2 +=1;
				}
				//sleep(1);
			}
			
		}
		if (nb_victoire_joueur1> nb_victoire_joueur2)
		{
			vainqueur=1;
		} else if (nb_victoire_joueur2>nb_victoire_joueur1)
		{
			vainqueur=2;
		}
		printf("le vainqueur est le joueur %d \n",vainqueur);
		printf("Avec %d victoires contre %d victoires",nb_victoire_joueur1,nb_victoire_joueur2);
		printf("Voulez vous relancer une partie ?\n 1=Oui, 0=Non \n");
		scanf("%d",&again);
	}
    return EXIT_SUCCESS; // Everything went well
}
