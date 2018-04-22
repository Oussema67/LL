#include "Deck.h"

deck::deck(){
	size = 0;
	cards.resize(size);
}

void deck::addCards(hand& h){
	while(!h.empty()){		
		addCard(h.thisCard(h.howManyCards()-1));
		h.removeCard(h.thisCard(h.howManyCards()-1));
	}
}

bool deck::shuffle(){
	shuffle1();
	shuffle2();
	shuffle2();
	shuffle2();
	shuffle2();
	shuffle1();
	return true;
}

void deck::shuffle1(){
    srand ( unsigned ( std::time(0) ) );
    //srand(60);
	random_shuffle ( cards.begin(), cards.end() );
}

void deck::shuffle2(){
	hand h1 = hand();
	hand h2 = hand();
	int ogSize = size;
	while(size != 0){		
		if(size > ogSize/2){
			h1.addCard(cards[size-1]);
			removeCard(cards[size-1]);
		}else{
			h2.addCard(cards[size-1]);
			removeCard(cards[size-1]);
		}
	}
	while(size < ogSize){
		if(!h1.empty()){
			addCard(h1.thisCard(0));
			h1.removeCard(h1.thisCard(0));
		}
		if(!h2.empty()){
			addCard(h2.thisCard(0));
			h2.removeCard(h2.thisCard(0));
		}
	}
}

card deck::drawTop(){
	card topCard;
	if(!empty()){
		topCard = cards[0];
		removeCard(topCard);
		return topCard;
	}
	else{
		cout << "No Cards in Deck..." << endl;
		return topCard;
	}
}

void deck::createDeck(){

    card guard = card(1,guess,"Guard","Name a non-Guard card\nand choose another player.\nIf that player has that card,\nhe or she is out of the round");
    card guard2 = card(1,guess,"Guard","Name a non-Guard card\nand choose another player.\nIf that player has that card,\nhe or she is out of the round");
    card guard3 = card(1,guess,"Guard","Name a non-Guard card\nand choose another player.\nIf that player has that card,\nhe or she is out of the round");
    card guard4 = card(1,guess,"Guard","Name a non-Guard card\nand choose another player.\nIf that player has that card,\nhe or she is out of the round");
    card guard5 = card(1,guess,"Guard","Name a non-Guard card\nand choose another player.\nIf that player has that card,\nhe or she is out of the round");

    card priest = card(2,look,"Priest","Look at another player's hand.");
    card priest2 = card(2,look,"Priest","Look at another player's hand.");

    card baron = card(3,compare,"Baron","You and another player secretly\ncompare hands. The player with\n the lower value is out of the round.");
    card baron2 = card(3,compare,"Baron","You and another player secretly\ncompare hands. The player with\n the lower value is out of the round.");

    card handmaid = card(4,ignore,"Handmaid","Until your next turn, ignore all\neffects from other players' cards.");
    card handmaid2 = card(4,ignore,"Handmaid","Until your next turn, ignore all\neffects from other players' cards.");

    card prince = card(5,draw,"Prince","Choose any player (including\nyourself) to discard his or her\nhand and draw a new card.");
    card prince2 = card(5,draw,"Prince","Choose any player (including\nyourself) to discard his or her\nhand and draw a new card.");

    card king = card(6,trade,"King","Trade hands with another\nplayer of your choice");

    card countess = card(7,discard,"Countess","If you have this card and the\nKing or Prince in your hand,\nyou must discard this card.");

    card princess = card(8,lose,"Princess","If you discard this card\nyou are out of the round");


    addCard(guard);
    addCard(prince2);
    addCard(baron2);
    addCard(princess);
    addCard(countess);
    addCard(king);
    addCard(guard3);
    addCard(prince);
    addCard(guard4);
    addCard(guard5);
	addCard(priest);
    addCard(priest2);
	addCard(baron);
    addCard(guard2);
	addCard(handmaid);
    addCard(handmaid2);
	addCard(countess);

}
