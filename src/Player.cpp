#include "Player.hpp"


Player::Player(char _color) : color(_color) {
    //
}

std::tuple<int, char> Player::glouton_interne(Board const &board, char playercolor, int nb_coups_avance) {
    if (nb_coups_avance < 1) {
        std::cout << "Board::glouton_interne appelé avaec un niveau égal à " << nb_coups_avance << ". nb_coups_avance doit être supérieur à 1." << std::endl;
        exit(1);
    } else if (nb_coups_avance == 1) {
        int aire[7] = {0, 0, 0, 0, 0, 0, 0};
        char chosencolor = 'A';
        for (int i = 0; i < 7; i++) {
            Board *copy = board.copy();

            board.destroyCopy(copy);
        }
    }
}

char Player::glouton(Board const &board, int nb_coups_avance) {
    int aire;
    char choix;
    std::tie(aire, choix) = this->glouton_interne(board, this->getColor(), nb_coups_avance);
    return choix;
}


int Player::getNbVictory() {
    return this->nb_victory;
}


char Player::getColor(){
    return this->color;
}