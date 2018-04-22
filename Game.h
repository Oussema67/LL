#pragma once

#include "Deck.h"
#include "mainwindow.h"
#include "Player.h"
#include "carte_view.h"
using namespace std;

class game{
public:
    game(MainWindow* vue);
	void howManyPlayers(int);
	void setup();
	void theGame();
	void theEffect(card, player&);
	void turn(player&);
    void resume(int choice);
    static game* thegame;

    void guessWho_resume(int plint, int what);
    void compareWith_Resume(int plint);
    void drawAndDiscard_Resume(int plint);
    void tradeWith_Resume(int plint);
    void eliminatePlayer(int plint);

protected:
private:
    MainWindow* vue;
    player pl[4];
	deck theDeck;
	hand discardPile;
	bool whoIsPlaying[4];
	bool winner[4];
	int winNumber;	
	void guessWho();
	void lookAt();
	void compareWith(player&);
    void ignoreEverything(player&);
	void drawAndDiscard();
    void tradeWith(player&);
	void discardThis(player&);
    void loseGame(player&);
    int vhowManyPlayers;
    player* compare_p;
    player* tradewith_p;

    void endTurn();
    //IHM
    player& pickWho();
    player* pourResume;
    int player_mustplay;


};
