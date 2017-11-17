//
// Created by Roc Wang on 2017-11-09.
//

#include "Blocker.h"

Blocker::Blocker() : Chip() {}

Blocker::Blocker(int p, string l) : Chip(p, l) {}

Blocker::~Blocker() {}

void Blocker::powerUp(Board &b, int col) {
	// Set block to the column number
	b.setBlock(col + 1);
}

