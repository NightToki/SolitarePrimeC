#ifndef H_card
#define H_card
//#include <iostream>
using namespace std;

class card {
	// things given to us 
public: 
	card();
	card(char r, char s);
	int getValue() const;
	void setCard(char r, char s);
	void showCard() const;

private:// each card has different ranks and suits
	char rank;
	char suit;
};

#endif

