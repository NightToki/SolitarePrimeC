#include "Deck.h"
#include "iostream"
#include <stdlib.h>

deck::deck() {//Create a deck that will be in order
	// 4 rows of 13 
	// keep track of the top card
	char suits[] = { 'H','D','S','C' };
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	topCard = 0;
	int counter = 0;
	card card1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			card1 = card(ranks[j], suits[i]);
			deckFT[counter++] = card1;

		}
	}
}
//create a new deck and replace the old deck
void deck::refreshDeck() {
	deck();
}
// pull the top card of the deck
card deck::deal()
{
	return deckFT[topCard++];

}
//shuffle function without using any C++ functions
//use rand and figure it out later
// need to replace cards around
void deck::shuffle() {
	card shuffled;
	int x;
	for (int i = 0; i < 52; i++) {
		int j = (rand() + time(0)) % 52;
		shuffled = deckFT[i];
		deckFT[i] = deckFT[j];
		deckFT[j] = shuffled;
	}
}
//find # of cards in the deck so just subtrack the top card by 52
int deck::cardsLeft() const {
	return(52 - topCard);

}
//print the deck 
//use the show card function and make 4 rows of 13
void deck::showDeck() const {
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deckFT[x++].showCard();
			cout << " ";
		}
		cout << "" << endl;
	}

}