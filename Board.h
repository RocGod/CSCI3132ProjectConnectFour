//
// Created by Roc Wang on 2017-10-19.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H

#include "Chip.h"
#include "Newton.h"
#include "Blocker.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Chip;

class Newton;

class Blocker;

class Board {
	protected:
		unsigned int row;
		unsigned int column;
		vector<vector<Chip> > board;
		int block;
		int count;
		int fullCol;
		unsigned int newX;
		unsigned int newY;
	public:
		Board();

		~Board();

		void Display();

		int isWin();

		bool columnFull(int col);

		void add(int col, int p, string l, int type);

		void pop(int col);

		void setBlock(int col);

		int getBlock();

		int getFullCol();
};


#endif //PROJECT_BOARD_H
