//
// Created by Roc Wang on 2017-10-19.
//

#ifndef PROJECT_CHIP_H
#define PROJECT_CHIP_H

#include <iostream>

using namespace std;

class Board;

class Chip {
	protected:
		int player;
		string label;
	public:
		Chip();

		Chip(int p, string l);

		~Chip();

		void setLabel(string l);

		string getLabel();

		int getPlayer();

		virtual void powerUp(Board& b, int col);
};


#endif //PROJECT_CHIP_H
