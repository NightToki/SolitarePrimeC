#include "Card.h"
#include <string>
#include <iostream>

card::card() {
	rank = ' ';
	suit = ' ';
}
card::card(char r, char s) {
	rank = r;
	suit = s;

}
// print any given card, but T = 10 and not TD or anything 
//the rest just print rank and suit
void card::showCard() const { 
	 
	if(rank == 'T') {
		printf("%c%c%c", '1','0', suit);
	}
	else {
		printf("%c%c", rank, suit);

	}


	
}
void card::setCard(char r, char s) {
	rank = r;
	suit = s;
}
// to do: get value of each suit
// change the value from a character into an int and then add it 
// how to typecast?
int card::getValue() const {
	switch (rank) {
	case 'A':
		return 1;
	case 'K':
		return 10;
	case 'Q':
		return 10;
	case 'J':
		return 10;
	case 'T':
		return 10;
	default:
		int rankValue;
		rankValue = rank - '0';
		return rankValue;






	}


}



