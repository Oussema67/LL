#include "Player.h"


player::player(){
	name = "Person";
	points = 0;
    vue = new Joueur_view();
    myHand = hand(vue);
    invulnerable=false;
}

player::player(string n, int p, int aid){
	name = n;
	points = p;
    vue = new Joueur_view();
    myHand = hand(vue);
    invulnerable=false;
    id=aid;
}

bool player::drawCard(deck& d){
    card draw = d.drawTop();
    myHand.addCard(draw);

	return true;
}

effect player::playCard(int c, hand& d){
	card f = myHand.thisCard(c);
	effect e; 
	e = f.getAbility();
	d.addCard(f);
	myHand.removeCard(f);
	return e;
}

void player::lookAtHand(){
	myHand.lookAtCards();
}

card player::getCard(int i){
	return myHand.thisCard(i);
}

void player::deleteCard(int i){
    myHand.removeCard(myHand.thisCard(i));
}
void player::discardCard(int i, hand& dis){
	dis.addCard(myHand.thisCard(i));
    this->vue->discardCard(myHand.thisCard(i).vue);
    myHand.thisCard(i).vue->unveil();
	myHand.removeCard(myHand.thisCard(i));

}

int player::getCardValue(card c){
	return c.getValue();
}

void player::addCard(card c){
	myHand.addCard(c);
}
