
#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
#include <unordered_map>

enum class Suit { Clubs, Diamonds, Hearts, Spades };
enum class Rank { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:
    Card(Rank r, Suit s);

    Rank getRank() const;
    Suit getSuit() const;

    int getValue() const;
    void print() const;

private:
    Suit cardSuit;
    Rank cardRank;
};

std::ostream& operator <<(std::ostream& out, const Card& c);


#endif
