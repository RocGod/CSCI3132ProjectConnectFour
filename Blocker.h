//
// Created by Roc Wang on 2017-11-09.
//

#ifndef PROJECT_BLOCKER_H
#define PROJECT_BLOCKER_H

#include "Chip.h"
#include "Board.h"

class Board;

class Chip;

class Blocker : public Chip {
	public:
		Blocker();

		Blocker(int p, string l);

		~Blocker();

		void powerUp(Board &b, int col);

};

#endif //PROJECT_BLOCKER_H

