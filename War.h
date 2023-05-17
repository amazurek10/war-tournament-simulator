#ifndef WAR_H_
#define WAR_H_

#include <deque>
#include <cstdlib>
#include <algorithm>
#include <random>

#include "Player.h"
#include "Card.h"

class War {
public:
	War(const Player& p1, const Player& p2);

	// Important pre-game functions
	std::deque<Card> generateDeck();
	void distributeCards(Player& p1, Player& p2);

	Player playGame();




	// For debugging purposes
	/*void printDeck() {
		for (int i = 0; i < deck.size(); i++) {
			std::cout << deck[i] << std::endl;
		}
	}
	void printP1Cards() {
		for (int i = 0; i < p1_cards.size(); i++) {
			std::cout << p1_cards[i] << std::endl;
		}
	}
	void printP2Cards() {
		for (int i = 0; i < p2_cards.size(); i++) {
			std::cout << p2_cards[i] << std::endl;
		}
	}*/
private:
	Player playerOne;
	Player playerTwo;
	std::deque<Card> deck;
	std::deque<Card> p1_cards;
	std::deque<Card> p2_cards;
	int battleRound;
};




#endif // !WAR_H_
