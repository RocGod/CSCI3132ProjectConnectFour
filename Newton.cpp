//
// Created by Roc Wang on 2017-11-09.
//

#include "Newton.h"

Newton::Newton() : Chip() {}

Newton::Newton(int p, string l) : Chip(p, l) {}

Newton::~Newton() {}

void Newton::powerUp(Board &b, int col) {
	b.pop(col);
}

