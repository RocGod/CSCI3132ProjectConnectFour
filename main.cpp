#include <iostream>
#include "Board.h"
#include "GamePlayer.h"

int inputChips(string name);

int main() {
	int column_to_insert, randNum;
	int type = 0;
	int skip = 0;
	string name;
	int turn = 0;
	string label;
	Board *board = new Board();
	cout << "GamePlayer 1 name: ";
	cin >> name;
	Human *player1 = new GamePlayer(name, "⚑");
	cout << "GamePlayer 2 name: ";
	cin >> name;
	Human *player2 = new GamePlayer(name, "⚐");
	name = player1->getName();
	label = player1->getLabel();
	while (board->isWin() == 0) {
		board->Display();
		if (skip == 0) {
			srand(time(NULL));
			randNum = rand() % (100) + 1;
			if (randNum % 25 == 0 && board->getFullCol() < 6) {//percentage is 4%
				type = 2;
				if (turn == 0)
					label = "■";
				else
					label = "□";
				cout << "Current chip is Blocker" << endl;
			} else if (randNum % 12 == 0) { //probability is 8%
				type = 1;
				if (turn == 0)
					label = "▼";
				else
					label = "▽";
				cout << "Current chip is Newton" << endl;
			} else {
				//Normal chip type
				type = 0;
				if (turn == 0)
					label = "⚑";
				else
					label = "⚐";
			}
		}
		//If placing chip fails, skip random type generation, which is controlled by int skip
		if (board->getBlock() != 0) {
			cout << "Column " << board->getBlock() << " is blocked" << endl;
		}

		column_to_insert = inputChips(name);
		if (!board->columnFull(column_to_insert - 1)) {
			skip = 1;
			cout << "The column is full, please select another column" << endl;
			continue;
		}

		if (board->getBlock() == column_to_insert) {
			skip = 1;
			cout << "The column is blocked, please select another column" << endl;
			continue;
		}

		board->add(column_to_insert - 1, turn, label, type);
		if (skip == 1)
			skip = 0;
		if (turn == 0) {
			label = player2->getLabel();
			name = player2->getName();
			turn = 1;
		} else {
			label = player1->getLabel();
			name = player1->getName();
			turn = 0;
		}
	}

	board->Display();
	if (board->isWin() == 1) {
		cout << player1->getName() << " WIN !" << endl;
	} else if (board->isWin() == 2) {
		cout << player2->getName() << " WIN !" << endl;
	} else {
		cout << "Draw !" << endl;
	}
	return 0;
}

int inputChips(string name) {
	int col;
	while (true) {
		cout << "GamePlayer " << name << " input a column 1-7: ";
		cin >> col;
		if (col > 0 && col < 8)
			break;
	}
	return col;
}