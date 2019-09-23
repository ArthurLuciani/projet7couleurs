#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ncurses.h>
#include <tuple>
#include <queue>

//#include "Player.hpp"
#include "divers.hpp"
class Board {

    protected:
        char **tab;
        int size;
        char colorplayer1;
        char colorplayer2;
        char **copyTab();
        void destroyCopyTab(char **&newtab);
        void setTab(char const **tab);
        Board(const int _size, const char _colorplayer1, const char _colorplayer2, char **const _tab);

    public:
        Board(int _size, char _playercolor1, char _playercolor2);
        ~Board();  // todo

        Board *copy() const;
        void destroyCopy(Board *&copy) const;

        char getCell(int x, int y);
        void setCell(int x, int y, char value);
        int getSize();
        void show();
        int paint(int x, int y, char playercolor, char choix);
        int update(char playercolor, char choix);
        int getPerimeterSize(char playercolor);
        bool isBetween(char **copy, int x, int y, char min, char max);
        bool bordercolorpresence(char chosencolor, char playercolor);
};

#endif