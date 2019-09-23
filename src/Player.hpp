#ifndef PLAYER_H
#define PLAYER_H


#include <tuple>
#include <iostream>

#include "Board.hpp"


class Player {

    private:
        int strategie;
		int nb_victory;
		char color;
		std::tuple<int, char> glouton_interne(Board const &board, char playercolor, int nb_coups_avance);

    public:
		char getColor();
		int getNbVictory();
		void addAVictory();
		char glouton(Board const &board, int nb_coups_avance);
        Player(char _color);//selection player
        //et pe le gros switch:
        /*switch(strategie_joueur1)
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
        */
        int getStrategie();
};


#endif