#pragma once
#include <vector>
#include "Card.h"

#include "joueur_view.h"

using namespace std;

class hand{
public:
    Joueur_view* possessor;
    hand(Joueur_view* poss = 0);
	void addCard(card);
	bool removeCard(card);
	void lookAtCards();
	int howManyCards();
	card thisCard(int);
	bool empty();//Are the no more cards?
    void slide();
protected:	
	int size;
	vector<card> cards;
private:

};
