#include "Game.h"
#include <cstdio>



game::game(MainWindow* vue){
    this->vue=vue;

    pl[0] = player("Bob",0,0);
    pl[1] = player("Bertta",0,1);
    pl[2] = player("George",0,2);
    pl[3] = player("Julien",0,3);
    player_mustplay=0;
	theDeck = deck();
	discardPile = hand();

    vhowManyPlayers =0;
	winNumber = 7;
	theDeck.createDeck();
	whoIsPlaying[0] = false;
	whoIsPlaying[1] = false;
	whoIsPlaying[2] = false;
	whoIsPlaying[3] = false;
	winner[0] = false;
	winner[1] = false;
	winner[2] = false;
	winner[3] = false;





}

void game::howManyPlayers(int numberOfPlayers){
	for(int i = 0; i < numberOfPlayers; i++){
		whoIsPlaying[i] = true;
		winner[i] = true;
        vue->addChildJoueurView(pl[i].vue, i);
        vhowManyPlayers=numberOfPlayers;
	}
}

void game::setup(){
    //theDeck.shuffle();
	discardPile.addCard(theDeck.drawTop());
	for(int i = 0; i < 4; i++){
		if(whoIsPlaying[i] == true){
            pl[i].drawCard(theDeck);
            pl[i].getCard(0).vue->veil();
		}
	}
}

void game::theGame(){
    turn(pl[player_mustplay]);
}

void game::endTurn(){
    int i = 0;
    player_mustplay=(player_mustplay+1)%vhowManyPlayers;
    while(!whoIsPlaying[player_mustplay])
    {
     player_mustplay=(player_mustplay+1)%vhowManyPlayers;
     i++;
     if(i>vhowManyPlayers)
     perror("aucun joueur en vie?");
    }
    turn(pl[player_mustplay]);

}

void game::turn(player& you){
    pourResume=&you;

    if(you.invulnerable)
    {
        you.invulnerable=false;
        you.vue->VstopIgnore();
    }

	you.drawCard(theDeck);
    //Test contesse
    if(you.myHand.thisCard(0).name.compare(string("Countess"))==0
            &&(you.myHand.thisCard(1).name.compare(string("Prince"))==0
                || you.myHand.thisCard(1).name.compare(string("King"))==0
                ))
    {

        you.discardCard(0,discardPile);
        you.myHand.slide();
        endTurn();
    }
    else  if(you.myHand.thisCard(1).name.compare(string("Countess"))==0
             &&(you.myHand.thisCard(0).name.compare(string("Prince"))==0
                 || you.myHand.thisCard(0).name.compare(string("King"))==0
                 ))
    {
        you.discardCard(1,discardPile);
        endTurn();
    }
    else {


    you.vue->turnOn();
    you.getCard(0).vue->unveil();
    you.vue->mustplay=true;
    }

    /*
	you.lookAtHand();
	int choice;
	cout << "[0]First card \n\tor \n[1] Second Card?" << endl;
	cin >> choice;
	cout << "You played " << endl;
	you.getCard(choice).readCard();
	theEffect(you.getCard(choice), you);
	you.discardCard(choice,discardPile);
    */
}


void game::resume(int choice){
    player& you = *pourResume;

    //you.lookAtHand();

    //you.getCard(choice).readCard();
    card c=you.getCard(choice);
    you.discardCard(choice,discardPile);
    //Glisser la carte en [1] en [0] au besoin
    if(choice==0)
    {
        you.myHand.slide();
    }
    theEffect(c, you);


    you.vue->turnOff();
    you.getCard(0).vue->veil();


    endTurn();

}

//Ça, ça devrait vraimejj
void game::theEffect(card c, player& p){
	enum effect {guess,look,compare,ignore,draw,trade,discard,lose};
	switch(c.getAbility()){
	case guess:
        guessWho();
		break;
	case look:
		lookAt();
		break;
	case compare:
		compareWith(p);
		break;
	case ignore:
        ignoreEverything(p);
		break;
	case draw:
		drawAndDiscard();
		break;
	case trade:
		tradeWith(p);
		break;
	case discard:
		void discardThis();
		break;
	case lose:
        loseGame(p);
		break;
	default:
		cout << "nothing" << endl;
		break;
	}

}

void game::guessWho(){
    this->vue->guessWho();
    /*
	player p;
	p = pickWho();
	int what;
	bool y = false;
	while(!y){
		cout << "What card do they have?" << endl;
		cout << "[2] Priest\n[3] Baron\n[4] Handmaid\n[5] Prince\n[6] King\n[7] Countess\n[8] Princess" << endl;
		cin >> what;
		if(!(what > 8 || what < 2)){
			y = true;
			if(p.getCardValue(p.getCard(0)) == what){
				cout << "You were right!" << endl;
			}else{
				cout << "You were wrong" << endl;
			}
		}
	}
    */
}

void game::guessWho_resume(int plint, int what)
{
    player p = pl[plint];
    bool y = false;
    while(!y){
        if(!(what > 8 || what < 2)){
            y = true;
            if(p.getCardValue(p.getCard(0)) == what){
               eliminatePlayer(plint);
            }else{
                cout << "You were wrong" << endl;
            }
        }
    }

}

void game::lookAt(){
    /*
	player p;
	p = pickWho();
	p.lookAtHand();
	printf("\n");
    */
}

void game::compareWith(player& you){
    compare_p = &you;
    this->vue->VCompareWith();


}

void game::compareWith_Resume(int plint){

    player p = pl[plint];
    if(p.getCardValue(p.getCard(0)) < compare_p->getCardValue(compare_p->getCard(0))){
        eliminatePlayer(plint);
    }else if(p.getCardValue(p.getCard(0)) > compare_p->getCardValue(compare_p->getCard(0))){
        eliminatePlayer(compare_p->id);
        cout << "You Lose" << endl;
    }

}

void game::ignoreEverything(player& you){

	cout << "Protection until your next turn" << endl;
    you.invulnerable=true;
    you.vue->VignoreEverything();
}

void game::drawAndDiscard(){
    this->vue->VdrawAndDiscard();
    /*
	player p;
	p = pickWho();
	p.discardCard(0,discardPile);
	p.drawCard(theDeck);
    */
}

void game::drawAndDiscard_Resume(int plint){
    //player p =pl[plint];
    if(pl[plint].getCard(0).getValue()==8)
    {
        pl[plint].discardCard(0,discardPile);
        eliminatePlayer(plint);
    }
    else {
        pl[plint].discardCard(0,discardPile);
        pl[plint].drawCard(theDeck);

    }

}

void game::tradeWith(player &you){
    tradewith_p=&you;
    this->vue->VtradeWith();
    /*
	card c;
	cout << "Trade hands" << endl;
	player p;
	p = pickWho();
	c = p.getCard(0);
	you.addCard(c);
	c = you.getCard(0);
	p.addCard(c);
	you.deleteCard(0);
	p.deleteCard(0);
    */
}

void game::tradeWith_Resume(int plint){
    card c;



    cout << tradewith_p->getCard(0).name << endl;
    //cout << you.getCard(1).name << endl;
    cout << pl[plint].getCard(0).name << endl;
    //cout << p.getCard(1).name << endl;
    cout << "-----------------" << endl;
    c = pl[plint].getCard(0);

    tradewith_p->addCard(c);

    pl[plint].deleteCard(0);
    cout << tradewith_p->getCard(0).name << endl;
    cout << tradewith_p->getCard(1).name << endl;
    cout << pl[plint].getCard(0).name << endl;
    //cout << p.getCard(1).name << endl;
    cout << "-----------------" << endl;
    c = tradewith_p->getCard(0);
    pl[plint].addCard(c);
    tradewith_p->deleteCard(0);
    cout << tradewith_p->getCard(0).name << endl;
    cout << pl[plint].getCard(0).name << endl;
    cout << "-----------------" << endl;

    tradewith_p->myHand.slide();

    //c = you.getCard(0);

    //you.deleteCard(0);
    //p.deleteCard(0);

}

void game::discardThis(player& p){
	cout << "Discard if caught with King or Prince" << endl;
	if(p.getCardValue(p.getCard(0)) == 7)
		p.discardCard(0, discardPile);
	else
		p.discardCard(1,discardPile);
}

void game::loseGame(player& p){
	cout << "Lose if discarded" << endl;
    eliminatePlayer(p.id);
}
player& game::pickWho(){
	int who;
	while(true){
		cout << "Choose a Player" << endl;
		cout << "[0] Player1\n[1] Player2\n[2] Player3\n[3] Player4" << endl;
		cin >> who;
		if(!(who > 3 || who < 0))
			return pl[who];
	}
}

void game::eliminatePlayer(int plint){
    whoIsPlaying[plint]=false;
    if(pl[plint].myHand.howManyCards()>0)
    {
        pl[plint].discardCard(0,discardPile);
    }
    pl[plint].vue->Veliminate();
}
