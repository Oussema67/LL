#pragma once
#include "Deck.h"
#include "joueur_view.h"




using namespace std;


class player{
public:
	player();
    player(string, int, int);
	bool drawCard(deck&);
	effect playCard(int,hand&);
	card getCard(int);
	int getCardValue(card);
	void deleteCard(int);
	void discardCard(int,hand&);
	void lookAtHand();
	void addCard(card);
    Joueur_view* vue;
    bool invulnerable;
    hand myHand;
    int id;
protected:

private:

	string name;
	int points;
};
