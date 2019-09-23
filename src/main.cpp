#include <ncurses.h>

#include "main.hpp"
#include "constantes.hpp"

#include "Board.hpp"
#include "Player.hpp"
// #define NCURSE_CHOICE


// int get_perimeter_size(char* board, char player)
// {
// 	char tmp_board[BOARD_SIZE * BOARD_SIZE];
// 	for (int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
// 	{
// 		tmp_board[i] = board[i];
// 	}

//   int perimeter = 0;
// 	for (int i=0; i < BOARD_SIZE; i++)
// 	{
// 		for (int j=0; j < BOARD_SIZE; j++)
// 		{
// 			if (get_cell(tmp_board, i, j) == player)
// 			{
//                 if ((i - 1) >= 0)
//                 {
//                     if (get_cell(tmp_board, i - 1, j) != P1_COLOR &&
//                         get_cell(tmp_board, i - 1, j) != P2_COLOR &&
//                         get_cell(tmp_board, i - 1, j) != '0')
//                     {
//                         perimeter += 1;
//                         set_cell(tmp_board, i-1, j, '0');
//                     }
//                 }
//                 if ((i + 1) < BOARD_SIZE)
//                 {
//                     if (get_cell(tmp_board, i + 1, j) != P1_COLOR &&
//                         get_cell(tmp_board, i + 1, j) != P2_COLOR && 
//                         get_cell(tmp_board, i + 1, j) != '0')
//                     {
//                         perimeter += 1;
//                         set_cell(tmp_board, i + 1, j, '0');
//                     }
//                 }
// 				if ((j-1)>=0)  
//                 {
//                     if (get_cell(tmp_board, i, j - 1) != P1_COLOR &&
//                         get_cell(tmp_board, i, j - 1) != P2_COLOR && 
//                         get_cell(tmp_board, i, j - 1) != '0')
//                     {
//                         perimeter += 1;
//                         set_cell(tmp_board, i, j - 1, '0');
//                     }
//                 }
//                 if ((j + 1) < BOARD_SIZE)
//                 {
//                     if (get_cell(tmp_board, i, j + 1) != P1_COLOR &&
//                         get_cell(tmp_board, i, j + 1) != P2_COLOR && 
//                         get_cell(tmp_board, i, j + 1) != '0')
//                     {
//                         perimeter += 1;
//                         set_cell(tmp_board, i, j + 1, '0');
//                     }
//                 }
//             }
//         }
//     }
//     return perimeter;
// }



// int bordercolorpresence(char chosencolor, char* board, char player)
// {
// 	int colorpresence = 0;
	
// 	for (int i=0; i < BOARD_SIZE; i++)
// 	{
// 		for (int j=0; j < BOARD_SIZE; j++)
// 		{
// 			if (get_cell(board, i, j) == player)
// 			{
// 				if ((i - 1) >= 0)
// 				{
// 					if (get_cell(board, i - 1, j) == chosencolor)
// 					{
// 						colorpresence = 1;
// 					}
// 				}
// 				if ((i + 1) < BOARD_SIZE)
// 				{
// 					if (get_cell(board, i + 1, j) == chosencolor)
// 					{
// 						colorpresence = 1;
// 					}
// 				}
// 				if ((j - 1) >= 0)
// 				{
// 					if (get_cell(board, i, j - 1) == chosencolor)
// 					{
// 						colorpresence = 1;
// 					}
// 				}
// 				if ((j + 1) < BOARD_SIZE)
// 				{
// 					if (get_cell(board, i, j + 1) == chosencolor)
// 					{
// 						colorpresence = 1;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return colorpresence;
// }
	

// int glouton_recu_count(char* board, char player, int glouton_count)
// {
//     int colorcounter[7] = {0, 0, 0, 0, 0, 0, 0};
//     char chosencolor = 'A';
// //    char temp_board_n[7][BOARD_SIZE * BOARD_SIZE];
//     char temp_board_n[BOARD_SIZE * BOARD_SIZE];
//     for(int k=0; k < 7; k++) //chaque couleur
//     {

//         for(int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
//         {
//             temp_board_n[i] = board[i];
//         }

//         colorcounter[k] = board_update_recu(temp_board_n, player, chosencolor);

//         if(glouton_count > 1)
//         {
//             colorcounter[k] += glouton_recu_count(temp_board_n, player, glouton_count - 1);
//         }

//         chosencolor++;
//     }

//     for(int i=1; i < 7; i++)
//     {
//         if (colorcounter[0] < colorcounter[i])
//         {
//             colorcounter[0] = colorcounter[i];
//         }
//     }

//     return colorcounter[0];
// }



// // ------------ Les joueurs --------------------------------------------


// char colorselect(char* board, char player)
// {
//     // joueur humain
//     char color;
//     while(color < 'A' || color > 'G')
//     {
//         //printf("Selectionnez une couleur : ");
//         //printf("\n");
//         color = getch();
//     }
//     return color;
// }

// char alea_computer(char* board, char player)
// {
//     // joueur aleatoire
//     return rand_a_b('A', 'G' + 1);
// }

// char alea_computer_ameliore(char* board, char player)
// {
// 	char chosencolor = 'P';
// 	do {
//         chosencolor = rand_a_b('A', 'G' + 1);
//     } while(bordercolorpresence(chosencolor, board, player) == 0);

//     return chosencolor;
// }


// char glouton(char* board, char player)
// {
//     int colorcounter[7] = {0, 0, 0, 0, 0, 0, 0};
//     int colornb = 0;
//     char chosencolor = 'A';


//     for(int k=0; k < 7; k++) //chaque couleur
//     {
//         for(int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
//         {
//             temp_board[i] = board[i];
//         }

//         colorcounter[k] += board_update_recu(temp_board, player, chosencolor);

//         chosencolor += 1;
//     }
//     chosencolor = 'A';
//     colornb = colorcounter[0];

//     for(int i=1; i < 7; i++)
//     {
//         if (colorcounter[i] > colornb)
//         {
//             colornb = colorcounter[i];
//             chosencolor = 'A' + i;
//         }
//     }
//     return chosencolor;
// }



// char glouton_2(char board[], char player)
// {
//     int colorcounter[7] = {0, 0, 0, 0, 0, 0, 0};
//     int colorcounter_2[7] = {0, 0, 0, 0, 0, 0};
//     char temp_board[BOARD_SIZE * BOARD_SIZE];
//     char temp_board_2[BOARD_SIZE * BOARD_SIZE];
// 	int chosencolor = 'A';
	
//     for(int k=0; k < 7; k++) //chaque couleur
//     {
//         for(int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) // init tableau
//         {
//             temp_board[i] = board[i];
//         }

//         colorcounter[k] += board_update_recu(temp_board, player, 'A' + k);

//         for(char color = 'A'; color <= 'G'; color++)
// 		{
// 			for(int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
// 			{
// 				temp_board_2[i] = temp_board[i];
// 			}
// 			colorcounter_2[color-'A'] = board_update_recu(temp_board_2, player, color);
// 		}
// 		for(int i=1; i < 7; i++)
// 		{
// 			if (colorcounter_2[0] < colorcounter_2[i])
// 			{
// 				colorcounter_2[0] = colorcounter_2[i];
// 			}
// 		}
// 		colorcounter[k] += colorcounter_2[0];
		
//         for (int j=0; j < 7; j++)
//         {
// 			colorcounter_2[j] = 0;
// 		}
//     }
       

//     for(int i=1; i < 7; i++)
//     {
//         if (colorcounter[0] <= colorcounter[i])
//         {
//             colorcounter[0] = colorcounter[i];
//             chosencolor='A' + i;
//         }
//     }
//     for(int i=0; i < BOARD_SIZE * BOARD_SIZE; i++) // init tableau
//     {
//         temp_board[i] = board[i];
//     }
//     if (board_update_recu(temp_board, player, chosencolor) == 0)
//     {
// 		chosencolor = glouton(board, player);
// 	}

//     return(chosencolor);
// }


// char glouton_n(char* board, char player)
// {
//     int glouton_count = (2); // > 1
//     int colorcounter[7] = {0, 0, 0, 0, 0, 0, 0};
//     char temp_board_n[BOARD_SIZE * BOARD_SIZE];
//     char chosencolor = 'A';
//     char best_color_yet = 'A';
//     int best_change = 0;
//     //debut recu
//     for(int k=0; k < 7; k++) //chaque couleur
//     {
//         for(int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
//         {
//             temp_board_n[i] = board[i];
//         }
//         colorcounter[k] += board_update_recu(temp_board_n, player, chosencolor);
//         if (colorcounter[k] > best_change)
//         {
//             best_change = colorcounter[k];
//             best_color_yet = 'A' + (char) k;
//         }
//         //printf("\n--- %d ---- %c ---\n", colorcounter[k], chosencolor);
//         colorcounter[k] += glouton_recu_count(temp_board_n, player, glouton_count - 1);

//         chosencolor++;
//     }
//     //fin recu
    
//     for(int i=1; i < 7; i++)
//     {
//         if (colorcounter[i] > best_change)
//         {
//             best_change = colorcounter[i];
//             best_color_yet = 'A' + (char) i;
//         }
//     }
//     return best_color_yet;
// }




// char hegemonique(char* board, char player)
// {
//     // implementation du joueur hegemonique (augmentation du perimetre)


//     int best_perimeter = get_perimeter_size(board, player);
//     char best_color = glouton(board, player);// couleur par defaut

//     int perimeter = 0;
//     printf("\n---------------test----------------\n");
//     //------char temp_board[BOARD_SIZE * BOARD_SIZE];
//     for(char color = 'A'; color <= 'G'; color++)
//     {
//         // on cree un plateau temporaire de test
//         //------printf("\n----color : %c ------\n", color);
//         for (int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
//         {
//             temp_board[i] = board[i];
//         }
//         board_update_recu(temp_board, player, color);
//         // detection du perimetre
//         perimeter = get_perimeter_size(temp_board, player);
//         if (perimeter > best_perimeter)
//         {
//             best_perimeter = perimeter;
//             best_color = color;
//             //print_board(temp_board);
//         }
//     }
//     // print_board(temp_board);
//     //printf("\nLa meilleur couleur pour %c est %c pour un perimetre de %d\n",player, best_color, best_perimeter);
//     return best_color;
// }




// char hybride(char* board, char player)
// {
// 	char color = 'A';
// //	static int changement;
// 	int perimeter = get_perimeter_size(board, player);
	
// 	if (changement == 1)
// 	{
// 		color = glouton_2(board, player);
// 	}
//     else
//     {
// 		color = hegemonique(board, player);
// 		if(get_perimeter_size(board, player) <= perimeter)
// 		{
// 			changement = 1;
// 		}
// 	}
// 	return color;
// }







// int selection_player()
// {
//     int strategie_joueur = 0;
//     while(strategie_joueur > 7 || strategie_joueur < 1)
// 	{
// 		printf("Selectioner le type de joueur :");
// 		printf("\n");
// 		printf("1=humain, 2=aleatoire, 3=aleatoire+, 4=glouton, 5=glouton_carre, 6=hegemonique, 7=hybride");
// 		printf("\n");
// 		scanf("%d", &strategie_joueur);
// 		printf("\n");
		
// 		if (strategie_joueur > 7 || strategie_joueur < 1)
// 		{
// 			while ((strategie_joueur=getchar()) != '\n' && strategie_joueur!= EOF) {}
// 		}

// 	}
// 	return strategie_joueur;
// }


// /** Program entry point */
// int main_origin()
// {
//     int DEBUG_MODE = 0;
//     bool again = true;
// 	while (again)
//     {
// 		again = false;
// 		srand(time(NULL));
// 		printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
// 		   "*****************************************************\n\n"
// 		   "Current board state:\n");
// 		int victory = 0;
// 		int nb_parties = 1;
// 		int nb_victoire_joueur1 = 0;
// 		int nb_victoire_joueur2 = 0;
// 		int count1 = 1;
// 		int count2 = 1;
// 		int vainqueur = 0;
// 		char color;   
// 		int strategie_joueur1 = 1;
// 		int strategie_joueur2 = 1;
//         if (!DEBUG_MODE)
//         {
//             strategie_joueur1 = selection_player();
//             strategie_joueur2 = selection_player();
//         }
//         else
//         {
//             // debug mod
//             strategie_joueur1 = 1;
//             strategie_joueur2 = 2;
//         }
// 		char (*pointeur_sur_fonction_joueur1)(char*,char);
// 		char (*pointeur_sur_fonction_joueur2)(char*,char);
// 		switch(strategie_joueur1)
// 		{
// 			case 1 :
// 				pointeur_sur_fonction_joueur1 = colorselect;
// 				break;
				
// 			case 2 :
// 				pointeur_sur_fonction_joueur1 = alea_computer;
// 				break;
				
// 			case 3 :
// 				pointeur_sur_fonction_joueur1 = alea_computer_ameliore;
// 				break;
				
// 			case 4 :
// 				pointeur_sur_fonction_joueur1 = glouton;
// 				break;
				
// 		   case 5 :
// 				pointeur_sur_fonction_joueur1 = glouton_n;
// 				break;
				
// 			case 6 :
// 				pointeur_sur_fonction_joueur1 = hegemonique;
// 				break;
// 			case 7 :
// 				pointeur_sur_fonction_joueur2 = hegemonique;
// 				break;
				
// 			default :
// 				pointeur_sur_fonction_joueur1 = colorselect;
// 				break;
// 		}
		
// 		switch(strategie_joueur2)
// 		{
// 			case 1 :
// 				pointeur_sur_fonction_joueur2 = colorselect;
// 				break;
				
// 			case 2 :
// 				pointeur_sur_fonction_joueur2 = alea_computer;
// 				break;
				
// 			case 3 :
// 				pointeur_sur_fonction_joueur2 = alea_computer_ameliore;
// 				break;
				
// 			case 4 :
// 				pointeur_sur_fonction_joueur2 = glouton;
// 				break;
				
// 			case 5 :
// 				pointeur_sur_fonction_joueur2 = glouton_n;
// 				break;
				
// 			case 6 :
// 				pointeur_sur_fonction_joueur2 = hegemonique;
// 				break;
				
// 			case 7:
// 				pointeur_sur_fonction_joueur2 = hybride;
// 				break;
				
// 			default :
// 				pointeur_sur_fonction_joueur2 = colorselect;
// 				break;
// 		}
		
// 		printf("entrer le nombre de partie que vous voulez jouer\n");
// 		scanf("%d", &nb_parties);
// 		printf("\n");
		
// 		for (int i=0; i < nb_parties; i++)
// 		{
//             initscr();
//             if(has_colors() == FALSE)
//             {	
//                 endwin();
//                 printf("Your terminal does not support color\n");
//                 exit(1);
//             }
//             start_color();			/* Start color 			*/
//             noecho();

// 			victory = 0;
// 			generate_aleat_board(board);
// 			count1 = 1;
// 			count2 = 1;
// 			changement = 0;
// 			while (victory == 0)
// 			{
// 				printw("Joueur 1 rentrez la couleur que vous souhaitez jouer ");
// 				color = (*pointeur_sur_fonction_joueur1)(board,P1_COLOR);
// 				printw("_%c_ \n", color);
// 				count1 += board_update_recu(board, P1_COLOR, color);
// 				if (strategie_joueur1 == 1)
// 				{
// 					//while ((color = getchar()) != '\n' && color!= EOF) {}
// 				}
// 				printw("l'occupation est de %d %% \n", (int)(count1 * 100 / pow(BOARD_SIZE, 2)));
// 				if (count1 >= (BOARD_SIZE * BOARD_SIZE / 2))
// 				{ 
// 					victory = 1;
// 					nb_victoire_joueur1 += 1;
// 				}
// 				printw("Joueur 2 rentrez la couleur que vous souhaitez jouer ");
// 				color = (*pointeur_sur_fonction_joueur2)(board, P2_COLOR);
// 				printw("_%c_\n", color);
// 				count2 += board_update_recu(board, P2_COLOR, color);
// 				if (strategie_joueur2 == 1)
// 				{
// 					while ((color = getchar()) != '\n' && color != EOF) {}
// 				}
//                 if (strategie_joueur1 == 1)
//                 {
                    // clear();
        //             refresh();
        //             print_board(board);
        //         }
		// 		printw("l'occupation est de %d %% \n", (int)(count2 * 100 / pow(BOARD_SIZE, 2)));
		// 		if (count2 >= (BOARD_SIZE * BOARD_SIZE / 2))
		// 		{ 
		// 			victory = 1;
		// 			nb_victoire_joueur2 += 1;
		// 		}
		// 		//sleep(1);
        //         endwin();
		// 	}
			
		// }
		// if (nb_victoire_joueur1 > nb_victoire_joueur2)
		// {
		// 	vainqueur = 1;
		// }
        // else if (nb_victoire_joueur2 > nb_victoire_joueur1)
		// {
		// 	vainqueur = 2;
		// }
// 		printf("le vainqueur est le joueur %d \n", vainqueur);
// 		printf("Avec %d victoires contre %d victoires", nb_victoire_joueur1, nb_victoire_joueur2);
// 		printf("Voulez vous relancer une partie ?\n 1=Oui, 0=Non \n");
// 		scanf("%d", &again);
// 	}
//     return EXIT_SUCCESS; // Everything went well
// }


void initScreen() {
    #ifdef NCURSE_CHOICE
    initscr();
    if(has_colors() == FALSE) {	
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();			/* Start color 			*/
    noecho();
    #endif
    #ifndef NCURSE_CHOICE
    std::cout << "mode sans echec" << std::endl;
    #endif
}


void cleanScreen() {
    #ifdef NCURSE_CHOICE
    clear();
    refresh();
    #endif
    #ifndef NCURSE_CHOICE
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl;
    }
    #endif
}


void destroyScreen() {
    #ifdef NCURSE_CHOICE
    endwin();
    #endif
}


int afficherVictoire(Player joueur1, Player joueur2) {
    int again;
    if (joueur1.getNbVictory() > joueur2.getNbVictory()) {
        printf("Le vainqueur est le joueur 1 !\n");
    } else if (joueur1.getNbVictory() < joueur2.getNbVictory()) {
        printf("Le vainqueur est le joueur 2 !\n");
    } else {
        printf("Égalité !\n");
    }
    printf("Avec %d victoires contre %d victoires", joueur1.getNbVictory(), joueur2.getNbVictory());
    printf("Voulez vous relancer une partie ?\n 1=Oui, 0=Non \n");
    scanf("%d", &again);
    return again;
}

/*
int main2() {
    DEBUG_MODE = 0;
    bool again = true;
	while (again) {
		again = false;
		std::cout << "Welcome to the 7 wonders of the world of the 7 colors" << std::endl;
		std::cout << "*****************************************************" << std::endl;
        std::cout << std::endl;
		std::cout << "Current board state:\n" << std::endl;
		bool victory = 0;
		int nb_parties = 1;
		int vainqueur = 0;
		char color;
        Player joueur1('.');
        Player joueur2('*');
		
		printf("entrer le nombre de partie que vous voulez jouer\n");
		scanf("%d", &nb_parties);
		printf("\n");
		
		for (int i=0; i < nb_parties; i++) {
			victory = false;
            Board plateau();

			while (!victory) {
				plateau.play(joueur1);
                plateau.showOccupation(joueur1);
				if (plateau.hasWin(joueur1)) { 
					victory = true;;
					joueur1.addAVictory();  // incremente le compteur de victoire
				}

				plateau.play(joueur1);
                plateau.showOccupation(joueur2);
				if (plateau.hasWin(joueur2)) { 
					victory = true;
					joueur2.addAVictory();  // incremente le compteur de victoire
				}

                cleanScreen();
                plateau.show();
                destroyScreen(); // todo: pourquoi ?
			}
			
		}
        again = afficherVictoire(joueur1, joueur2);
	}
    return EXIT_SUCCESS; // Everything went well
}*/

int main() {
    initScreen();
    std::cout << "avant initscr" << std::endl;
    initScreen();
    Player joueur1('.');
    Player joueur2('*');

    bool victory = false;
    std::cout << "Welcome to the 7 wonders of the world of the 7 colors" << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "Current board state:\n" << std::endl;
    Board plateau(7, joueur1.getColor(), joueur2.getColor());



    while (!victory) {
        plateau.play(joueur1);
        plateau.showOccupation(joueur1);
        if (plateau.hasWin(joueur1)) { 
            victory = true;;
            joueur1.addAVictory();  // incremente le compteur de victoire
        }

        plateau.play(joueur1);
        plateau.showOccupation(joueur2);
        if (plateau.hasWin(joueur2)) { 
            victory = true;
            joueur2.addAVictory();  // incremente le compteur de victoire
        }

        cleanScreen();
        plateau.show();
        destroyScreen(); // todo: pourquoi ?
    }
    sleep(1);

    destroyScreen();
    
    std::cout << "fin" << std::endl;
}