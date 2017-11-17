//
// Created by Roc Wang on 2017-10-19.
//

#ifndef PROJECT_GAMEPLAYER_H
#define PROJECT_GAMEPLAYER_H

#include "Human.h"

class GamePlayer : public Human {
	protected:
		string label;
	public:
		GamePlayer(string name, string l);

		void setLabel(string l);

		string getLabel();
};


#endif //PROJECT_GAMEPLAYER_H
