// Tony Tran
//CECS 282
//Steve GOld
// program 1 - solitare prime
// 2/9/2021

#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std;

//todo list:
//make the isPrime function that tells me if a number is prime or not
//create a menu that i can collect inputs from and call repeatedly when i put it in a loop so the game doesnt end after one use and people have the option to play as much as they want 
//create the game function
//create the loop that executes the choices of the menu
//is prime function
// i pulled this from my java one @.@ plz dont hurt me
bool isPrime(int x) {
	bool isPrime = true;
	if (x == 1) {
		isPrime = false;
	}
	for(int i = 2; i < x; i++) {
		if (x % i == 0) {
			isPrime = false;
		}
	}
	return isPrime;

}
//menu function needs to return 
int menu() {
	cout << "Welcome to Solitaire Prime!" << endl;
	while (true) {
		cout << "1) New Deck" << endl;
		cout << "2) Display Deck" << endl;
		cout << "3) Shuffle Deck" << endl;
		cout << "4) Play Solitare Prime" << endl;
		cout << "5) Exit" << endl;
		cout << "Please select a menu choice: " << endl;
		int userInt;
		cin >> userInt;// add a return statement or else suffer the errors later lol 
		return userInt;
	}
}


//to do:
// keep track of how many times a prime pile has appeared
// keep track of the sum and add it so it becomesa prime
//implement the is prime and pass in the sum to check if it's prime or  not 
// how the game plays....
/* deal a card and count it if it's prime end the pile
* if it's not prime then continue to add another card from the top of the deck
* print the card as  well
* play the game until the deck runs out of cards 
* if i am unable to get a prime as the last pile then you lose 
* if you get a prime on the last pile then procceed to get a primeCounter and add that show the player how many primes they got before they won
* add to the counters 
*/

void solitarePrime(deck deck) {
	int primeCounter = 0;
	int sum = 0;
	cout << "Solitare Prime" << endl;
	while (deck.cardsLeft() > 0) {
		card card = deck.deal();
		card.showCard();
		cout << ", ";
		sum += card.getValue();
		if (deck.cardsLeft() == 0) {
			if (isPrime(sum)) {
				primeCounter++;
				cout << "\nPrime: " << sum << endl;
				cout << "You have won in " << primeCounter << " rounds"<<endl;

			}
			else {
				cout << "You Lose!"<<endl;

			}
		}
		else if (isPrime(sum)) {
			cout << "Prime: " << sum << endl;
			sum = 0;
			primeCounter++;
		}
	}
}
/*switch and while loop to loop
* 1 new deck
* 2 display deck
* 3 shuffle deck
* 4 play the game
* 5 exit the game
* 6 anything that isnt an option prompt them to retry
*/
int main() {
	bool countinue = true;
	deck newDeck = deck();
	while (countinue == true) {
		int choice = menu();
		switch (choice) {

			case 1:
				newDeck = deck();
				break;
			case 2:
				newDeck.showDeck();
				break;
			case 3:
				newDeck.shuffle();
				break;
			case 4:
				solitarePrime(newDeck);
				break;
			case 5:
				cout << "GoodBye";
				countinue = false;
				break;
			default:
				cout << "This is not a valid input" << endl;
				break;
		}

	}
}