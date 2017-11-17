//
// Created by Roc Wang on 2017-10-19.
//

#include "Board.h"

Board::Board() {
	block = 0;
	row = 6;
	column = 7;
	fullCol = 0;

	// Variable for the indice of the new chip
	newX = -1;
	newY = -1;

	// Set size of board
	for (unsigned int i = 0; i < column; i++) {
		vector<Chip> c;
		board.push_back(c);
	}
}

Board::~Board() {
}

void Board::Display() {
	for (int i = row - 1; i >= 0; i--) {
		cout << i + 1 << " ";
		for (unsigned int j = 0; j < board.size(); j++) {
			if (i + 1 > board[j].size()) {
				cout << "_" << " ";
			} else {
				cout << board[j][i].getLabel() << " ";
			}
		}
		cout << endl;
	}

	cout << " ";
	for (unsigned int i = 1; i <= board.size(); i++)
		cout << " " << i;
	cout << endl;
}

// Check whether the game is over
// Return 0 for false, 1 for player 1, 2 for player 2, 3 for draw
int Board::isWin() {
	// Game starts
	if (newX == -1 || newY == -1) {
		return 0;
	}

	int player = board[newX][newY].getPlayer();
	int connection = 1;

	//checks vertical
	if (newY >= 3) {
		//check the chips under the new chip
		for (int i = 0; i < 3; i++) {
			if (board[newX][newY - i - 1].getPlayer() == player) {
				connection++;
			}
		}

		if (connection >= 4) {
			return player + 1;
		} else {
			//reset connection
			connection = 1;
		}
	}

	//Checks horizontal
	//Checks left side
	for (int i = 0; i < min(newX, (unsigned int) 3); i++) {
		if (newX - i - 1 >= 0 && board[newX - i - 1].size() > newY) {
			if (board[newX - i - 1][newY].getPlayer() == player) {
				connection++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	//Checks right side
	for (int i = 0; i < min(column - newX - 1, (unsigned int) 3); i++) {
		if (newX + i + 1 < column && board[newX + i + 1].size() > newY) {
			if (board[newX + i + 1][newY].getPlayer() == player) {
				connection++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	if (connection >= 4) {
		return player + 1;
	} else {
		//reset connection
		connection = 1;
	}

	//checks diagonal bottom left to top right
	//Checks bottom left side
	for (int i = 0; i < min(min(newX, (unsigned int) 3), min(newY, (unsigned int) 3)); i++) {
		if (newX - i - 1 >= 0 && board[newX - i - 1].size() > newY - i - 1) {
			if (board[newX - i - 1][newY - i - 1].getPlayer() == player) {
				connection++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	//Checks top right side
	for (int i = 0; i < min(min(column - newX - 1, (unsigned int) 3), min(row - newY - 1, (unsigned int) 3)); i++) {
		if (newX + i + 1 < column && board[newX + i + 1].size() > newY + i + 1) {
			if (board[newX + i + 1][newY + i + 1].getPlayer() == player) {
				connection++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	if (connection >= 4) {
		return player + 1;
	} else {
		//reset connection
		connection = 1;
	}

	//checks diagonal top left to bottom right
	//Checks top left side
	for (int i = 0; i < min(min(newX, (unsigned int) 3), min(row - newY - 1, (unsigned int) 3)); i++) {
		if (newX - i - 1 >= 0 && board[newX - i - 1].size() > newY + i + 1) {
			if (board[newX - i - 1][newY + i + 1].getPlayer() == player) {
				connection++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	//Checks bottom right side
	for (int i = 0; i < min(min(column - newX - 1, (unsigned int) 3), min(newY, (unsigned int) 3)); i++) {
		if (newX + i + 1 < column && board[newX + i + 1].size() > newY - i - 1) {
			if (board[newX + i + 1][newY - i - 1].getPlayer() == player) {
				connection++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	if (connection >= 4) {
		return player + 1;
	} else {
		//reset connection
		connection = 1;
	}

	if (fullCol == column) {
		return 3;
	}

	return 0;
};

// Check whether a column is full
bool Board::columnFull(int col) {
	if (board[col].size() >= row) {
		return false;
	} else {
		return true;
	}
}

// Add a chip
void Board::add(int col, int p, string l, int type) {
	// Reset block for next turn
	if (this->getBlock() != 0) {
		this->setBlock(0);
	}

	Chip *c = new Chip;
	if (type == 1) {
		c = new Newton(p, l);
	} else if (type == 2) {
		c = new Blocker(p, l);
	} else {
		c = new Chip(p, l);
	}

	if (type != 0) {
		c->powerUp(*this, col);
	}

	board[col].push_back(*c);
	newX = col;
	newY = board[col].size() - 1;
	// A column is full
	if (board[col].size() == row)
		fullCol++;
}

void Board::pop(int col) {
	if (!board[col].empty()) {
		board[col].erase(board[col].begin());
	}
}

//Set the column number which is blocked
void Board::setBlock(int col) {
	block = col;
}

//Get the column number which is blocked
int Board::getBlock() {
	return block;
}


int Board::getFullCol() {
	return fullCol;
}
