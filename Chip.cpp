//
// Created by Roc Wang on 2017-10-19.
//

#include "Chip.h"
#include <string>
class Board;

Chip::Chip() {}

Chip::~Chip() {}

Chip::Chip(int p, string l) {
	player = p;
	label = l;
}

void Chip::setLabel(string l) {
	label = l;
}

string Chip::getLabel() {
	return label;
}

int Chip::getPlayer() {
	return player;
}

void Chip::powerUp(Board& b, int col) {
}
