#pragma once
#include <iostream>
#include <string>
#include "carte_view.h"
using namespace std;

enum effect {guess,look,compare,ignore,draw,trade,discard,lose};

class card{
public:
	card();
	card(int,effect,string,string);
	void readCard();
	int getValue();
	effect getAbility();
    Carte_view* vue;
    string name;

protected:
private:
	int value;
	effect ability;

	string description;
	
};
