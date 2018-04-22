#include "Hand.h"

hand::hand(Joueur_view *poss){
    possessor=poss;
	size = 0;
	cards.resize(size);
}

void hand::addCard(card c){
	size++;
	cards.resize(size);
	cards[size-1] = c;
    if(possessor!=0)
    {
        possessor->drawCard(c.vue,size);
    }
}

bool hand::removeCard(card c){
	if(size != 0){
		for(int i = 0; i < size; i++){
			if(c.getValue() == cards[i].getValue()){
                //if(possessor!=0)
                    //possessor->discardCard(c.vue);
                cards.erase(cards.begin()+i);
				size--;
				return true;
            }
		}
	}
	return false;
}

void hand::lookAtCards(){
	if(!empty()){
		for(int i = 0; i < size; i++){
			cards[i].readCard();
		}
	}
	else{		
		cout << "No Cards\n" << endl;
	}
}


bool hand::empty(){
	if(size == 0)
		return true;
	else 
		return false;
}

int hand::howManyCards(){
	return size;
}

card hand::thisCard(int i){
	return cards[i];
}

void hand::slide(){
    if(possessor!=0)
        possessor->Vslide(cards[0].vue);
}
