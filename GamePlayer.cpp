//
// Created by Roc Wang on 2017-10-19.
//

#include "GamePlayer.h"

GamePlayer::GamePlayer(string name, string l) : Human(name) {
	label = l;
}

void GamePlayer::setLabel(string l) {
	label = l;
}

string GamePlayer::getLabel() {
	return label;
}