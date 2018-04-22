#include "Card.h"

card::card(){
	value = 0;
	ability = lose;
	name = "card";
	description = "placeholder";
}

card::card(int v, effect a, string n, string d){
	value = v;
	ability = a;
	name = n;
    description = d;
    vue = new Carte_view(0,v);
}

void card::readCard(){

	cout << "--------------------" << endl;
	cout << value << " " << name << endl;
	cout << "--------------------" << endl;
	cout << description << endl;
	cout << "--------------------\n" << endl;
}

int card::getValue(){
	return value;
}

effect card::getAbility(){
	return ability;
}
