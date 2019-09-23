#include "Board.hpp"

Board::Board(int _size, char _colorplayer1, char _colorplayer2):
    size(_size), colorplayer1(_colorplayer1), colorplayer2(_colorplayer2) {
    this->tab = new char*[_size];
    std::cout << "fin constructeur" << std::endl;
    for (int i = 0; i < _size; i++) {
        this->tab[i] = new char[_size];
        for (int j = 0; j < _size; j++) {
            this->tab[i][j] = rand_a_b('A', 'G');
            // std::cout << this->tab[i][j];
        }
    }
    this->tab[0][_size - 1] = colorplayer1;
    this->tab[_size - 1][0] = colorplayer2;
}

Board::Board(const int _size, const char _colorplayer1, const char _colorplayer2, char **const _tab):
    size(_size), colorplayer1(_colorplayer1), colorplayer2(_colorplayer2) {
    this->tab = new char*[_size];
    for (int i = 0; i < _size; i++) {
        this->tab[i] = new char[_size];
        for (int j = 0; j < _size; j++) {
            this->tab[i][j] = _tab[i][j];
        }
    }
}


Board::~Board() {
    std::cout << "coucou" << std::endl;
    for (int i = 0; i < this->size; i++) {
        std::cout << "avant" << std::endl;
        delete[] this->tab[i];
        std::cout << "apres" << std::endl;
    }
    delete[] this->tab;
    std::cout << "fin destructeur" << std::endl;
}


char Board::getCell(int x, int y) {
    bool x_ok = ((x >= 0) && (x < this->getSize()));
    bool y_ok = ((y >= 0) && (y < this->getSize()));
    if (!(x_ok && y_ok)) {  // problem
        std::cout << "I have to give tab[" << x << "][" << y << "], however my size is " << this->getSize() << "." << std::endl;
        exit(1);
    }
    return this->tab[x][y];
}


void Board::setCell(int x, int y, char value) {
    this->tab[x][y] = value;
}


int Board::getSize() {
    return this->size;
}


void Board::show() {
    for (int x = 0; x < this->getSize(); x++) {
        for (int y = 0; y < this->getSize(); y++) {
            switch(this->getCell(x, y))
            {
                /*
                case 'A': printw(RED     "%c "   RESET, c); break;
                case 'B': printw(GREEN   "%c "   RESET, c); break;
                case 'C': printw(YELLOW  "%c "   RESET, c); break;
                case 'D': printw(BLUE    "%c "   RESET, c); break;
                case 'E': printw(MAGENTA "%c "   RESET, c); break;
                case 'F': printw(CYAN    "%c "   RESET, c); break;
                */
                
                default:
                    #ifdef NCURSE_CHOICE
                    printw("%c ", this->getCell(x, y));
                    #endif
                    #ifndef NCURSE_CHOICE
                    std::cout << this->getCell(x, y);
                    #endif
                    break;
            }
        }
        #ifdef NCURSE_CHOICE
        printw("%\n");
        #endif
        #ifndef NCURSE_CHOICE
        std::cout << std::endl;
        #endif
    }
}


int Board::paint(int x, int y, char colorplayer, char choix) {
    int nb_changement = 0;
    std::queue<std::tuple<int, int> > still_to_explore;

    still_to_explore.push(std::make_tuple(x, y));
    while (!still_to_explore.empty()) {
        std::tie(x, y) = still_to_explore.front();
        still_to_explore.pop();
        nb_changement += 1;
        this->setCell(x, y, colorplayer);
        if ((x > 0) && this->getCell(x - 1, y) == choix) {
            still_to_explore.push(std::make_tuple(x - 1, y));
        }
        if ((x + 1 < this->getSize()) && this->getCell(x + 1, y) == choix) {
            still_to_explore.push(std::make_tuple(x + 1, y));
        }
        if ((y > 0) && this->getCell(x, y - 1) == choix) {
            still_to_explore.push(std::make_tuple(x, y - 1));
        }
        if ((y +1 < this->getSize()) && this->getCell(x, y + 1) == choix) {
            still_to_explore.push(std::make_tuple(x, y + 1));
        }
    }
    return nb_changement;
}


int Board::update(char colorplayer, char choix) {
    int nb_changement = 0;
    //todo: un peu etrange d'iterer pendant que l'on met à jour le terrain. Mias ça marche...
	for (int x = 0; x < this->getSize(); x++) {
		for (int y = 0; y < this->getSize(); y++) {
            if (this->getCell(x, y) == colorplayer) {
                if ((x > 0) && (this->getCell(x - 1, y) == choix)) {
                    nb_changement += this->paint(x - 1, y, colorplayer, choix);
                }
                if ((x + 1 < this->getSize()) && (this->getCell(x - 1, y) == choix)) {
                    nb_changement += this->paint(x + 1, y, colorplayer, choix);
                }
                if ((y > 0) && (this->getCell(x, y - 1) == choix)) {
                    nb_changement += this->paint(x, y - 1, colorplayer, choix);
                }
                if ((y + 1 < this->getSize()) && (this->getCell(x, y + 1) == choix)) {
                    nb_changement += this->paint(x, y + 1, colorplayer, choix);
                }
            }
        }
    }
    return nb_changement;
}

char **Board::copyTab() {
    char **newtab = new char*[this->size];
    for (int i = 0; i < this->size; i++) {
        newtab[i] = new char[this->size];
        for (int j = 0; j < this->size; j++) {
            newtab[i][j] = this->tab[i][j];
        }
    }
    return newtab;
}


void Board::destroyCopyTab(char **&newtab) {
    for (int i = 0; i < this->size; i++) {
        delete[] newtab[i];
    }
    delete[] newtab;
}

bool Board::isBetween(char **copy, int x, int y, char min, char max) {
    return (copy[x][y] >= min && copy[x][y] <= max);
}


int Board::getPerimeterSize(char playercolor) {
    char **copy = this->copyTab();
    int perimeter = 0;

    for (int x = 0; x < this->getSize(); x++) {
        for (int y = 0; y < this->getSize(); y++) {
            if (copy[x][y] == playercolor) {
                if ((x > 0) && (this->isBetween(copy, x - 1, y, 'A', 'G'))) {
                    perimeter += 1;
                    copy[x - 1][y] = '0';
                }
                if ((x + 1 < this->size) && (this->isBetween(copy, x + 1, y, 'A', 'G'))) {
                    perimeter += 1;
                    copy[x + 1][y] = '0';
                }
                if ((y > 0) && (this->isBetween(copy, x, y - 1, 'A', 'G'))) {
                    perimeter += 1;
                    copy[x][y - 1] = '0';
                }
                if ((y + 1 < this->size) && (this->isBetween(copy, x, y + 1, 'A', 'G'))) {
                    perimeter += 1;
                    copy[x][y + 1] = '0';
                }
            }
        }
    }

    destroyCopyTab(copy);
    return perimeter;
}


bool Board::bordercolorpresence(char chosencolor, char playercolor) {
	for (int x = 0; x < this->size; x++) {
		for (int y = 0; y < this->size; y++) {
			if (this->getCell(x, y) == playercolor) {
				if ((x > 0) && this->getCell(x - 1, y) == chosencolor) {
					return true;
				}
				if ((x + 1 < this->getSize()) && this->getCell(x + 1, y) == chosencolor) {
					return true;
				}
				if ((y > 0) &&this->getCell(x, y - 1) == chosencolor) {
                    return true;
				}
				if ((y + 1 < this->getSize()) && this->getCell(x, y + 1) == chosencolor) {
                    return true;
                }
			}
		}
	}
	return false;
}





Board *Board::copy() const{
    Board *newboard = new Board(this->size, this->colorplayer1, this->colorplayer2, this->tab);
}

void Board::destroyCopy(Board *&copy) const {
    delete copy;
}