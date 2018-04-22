#pragma once
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "Hand.h"

using namespace std;

class deck: public hand{
public:
	deck();
	bool shuffle();
	void addCards(hand&);
	card drawTop();
	void createDeck();
private:
	void shuffle1();		
	void shuffle2();
protected:
};