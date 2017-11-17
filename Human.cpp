//
// Created by Roc Wang on 2017-10-19.
//

#include "Human.h"

Human::Human() {}

Human::Human(string name) {
	this->name = name;
}

Human::~Human() {}

void Human::setName(string name) {
	this->name = name;
}

string Human::getName() {
	return this->name;
}
