//
// Created by Roc Wang on 2017-11-09.
//

#ifndef PROJECT_NEWTON_H
#define PROJECT_NEWTON_H

#include "Chip.h"
#include "Board.h"

using namespace std;

class Chip;

class Board;

class Newton : public Chip {
	public:
		Newton();

		Newton(int p, string l);

		~Newton();

		void powerUp(Board &b, int col);

};


#endif //PROJECT_NEWTON_H
