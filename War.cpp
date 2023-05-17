#include "War.h"
#include "Card.h"

#include <algorithm>
#include <chrono>

War::War(const Player& p1, const Player& p2) {
	playerOne = p1;
	playerTwo = p2;
	battleRound = 0;

	this->deck = generateDeck();
	distributeCards(playerOne, playerTwo);
}

std::deque<Card> War::generateDeck() {
	std::deque<Card> d;

	for (int suit = 0; suit <= 3; suit++) {
		for (int value = 0; value <= 14; value++) {
			d.push_back(Card(static_cast<Rank>(value), static_cast<Suit>(suit)));
		}
	}

	// Shuffles cards
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(d.begin(), d.end(), std::default_random_engine(seed));

	return d;
}

void War::distributeCards(Player& p1, Player& p2) {

	for (int i = 0; i < deck.size(); i++) {
		if (i % 2 == 0) {
			p1_cards.push_back(deck[i]);
		}
		else {
			p2_cards.push_back(deck[i]);
		}
	}
}

Player War::playGame() {
	std::cout << playerOne.getName() << " vs. " << playerTwo.getName() << std::endl;

	do {
		++battleRound;

		// Draw cards to compare
		Card p1Card = p1_cards.front();
		p1_cards.pop_front();
		Card p2Card = p2_cards.front();
		p2_cards.pop_front();

		std::cout << "Round " << battleRound << ": ";
		std::cout << p1Card << " (" << p1_cards.size() << ") " << " vs. " << p2Card << " (" << p2_cards.size() << ")";
		std::cout << "          ";

		if (p1Card.getValue() > p2Card.getValue()) {
			// Player 1 wins both cards
			p1_cards.push_back(p1Card);
			p1_cards.push_back(p2Card);

			std::cout << playerOne.getName() << " has won the round." << std::endl;
		}
		else if (p1Card.getValue() < p2Card.getValue()) {
			// Player 2 wins both cards
			p2_cards.push_back(p2Card);
			p2_cards.push_back(p1Card);

			std::cout << playerTwo.getName() << " has won the round." << std::endl;
		}
		else {	// War

			// Check if war can even be played
			if (p1_cards.size() < 4 || p2_cards.size() < 4) {
				if (p1_cards.size() < p2_cards.size()) {
					std::cout << "Player 1 ran out of cards for war." << std::endl;
				}
				else if (p1_cards.size() > p2_cards.size()) {
					std::cout << "Player 2 ran out of cards for war." << std::endl;
				}
				else {
					std::cout << "Both players ran out of cards." << std::endl;
				}
			}
			else {
				std::deque<Card> pile;

				std::cout << "This means WAR!" << std::endl;

				// Each player put down 3 cards
				for (int i = 0; i < 3; i++) {
					pile.push_back(p1_cards.front());
					p1_cards.pop_front();
					pile.push_back(p2_cards.front());
					p2_cards.pop_front();
				}

				Card p1Card = p1_cards.front();
				p1_cards.pop_front();
				Card p2Card = p2_cards.front();
				p2_cards.pop_front();

				// Player 1 wins the war
				if (p1Card.getValue() > p2Card.getValue()) {
					while (!pile.empty()) {
						Card c = pile.front();
						pile.pop_front();
						p1_cards.push_back(c);
					}

					p1_cards.push_back(p1Card);
					p1_cards.push_back(p2Card);
				}
				else if (p1Card.getValue() < p2Card.getValue()) { // P2 wins the war
					while (!pile.empty()) {
						Card c = pile.front();
						pile.pop_front();
						p2_cards.push_back(c);
					}

					p2_cards.push_back(p2Card);
					p2_cards.push_back(p1Card);
				}

			}
		}



	} while (p1_cards.size() > 0 && p2_cards.size() > 0);

	if (p1_cards.empty()) {
		std::cout << playerTwo.getName() << " has won the game." << std::endl;
		
		return playerTwo;
	}
	else if (p2_cards.empty()) {
		std::cout << playerOne.getName() << " has won the game." << std::endl;

		return playerOne;
	}
}
