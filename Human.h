//
// Created by Roc Wang on 2017-10-19.
//

#ifndef PROJECT_HUMAN_H
#define PROJECT_HUMAN_H

#include <iostream>

using namespace std;

class Human {
	protected:
		string name;
	public:
		Human();

		Human(string name);

		~Human();

		void setName(string name);

		string getName();

		virtual string getLabel() = 0;
};


#endif //PROJECT_HUMAN_H
