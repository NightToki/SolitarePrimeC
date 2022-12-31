#ifndef H_Deck
#define H_Deck
#include "card.h"
using namespace std;

const int cardDeck = 52;

class deck {
public: // given to us
	deck();
	void refreshDeck();
	card deal();
	void shuffle();
	int cardsLeft() const;
	void showDeck() const;
private: // create an array of 52 cards 
	// keep track of what the top card of the deck is
	int topCard;
	card deckFT[52];
};

#endif
