#include "Card.h"

Card::Card(Rank r, Suit s) {
    cardRank = r;
    cardSuit = s;
}

Rank Card::getRank() const {
    return cardRank;
}

Suit Card::getSuit() const {
    return cardSuit;
}

int Card::getValue() const {
    switch (cardRank) {
    case Rank::Two:
        return 2;
    case Rank::Three:
        return 3;
    case Rank::Four:
        return 4;
    case Rank::Five:
        return 5;
    case Rank::Six:
        return 6;
    case Rank::Seven:
        return 7;
    case Rank::Eight:
        return 8;
    case Rank::Nine:
        return 9;
    case Rank::Ten:
        return 10;
    case Rank::Jack:
        return 11;
    case Rank::Queen:
        return 12;
    case Rank::King:
        return 13;
    case Rank::Ace:
        return 14;
    }
}

void Card::print() const {
    switch (getValue()) {
    case 2:
        std::cout << "2";
        break;
    case 3:
        std::cout << "3";
        break;
    case 4:
        std::cout << "4";
        break;
    case 5:
        std::cout << "5";
        break;
    case 6:
        std::cout << "6";
        break;
    case 7:
        std::cout << "7";
        break;
    case 8:
        std::cout << "8";
        break;
    case 9:
        std::cout << "9";
        break;
    case 10:
        std::cout << "10";
        break;
    case 11:
        std::cout << "Jack";
        break;
    case 12:
        std::cout << "Queen";
        break;
    case 13:
        std::cout << "King";
        break;
    case 14:
        std::cout << "Ace";
        break;
    }

    switch (cardSuit) {
    case Suit::Hearts:
        std::cout << " of Hearts";
        break;
    case Suit::Diamonds:
        std::cout << " of Diamonds";
        break;
    case Suit::Clubs:
        std::cout << " of Clubs";
        break;
    case Suit::Spades:
        std::cout << " of Spades";
        break;
    }
}

std::ostream& operator <<(std::ostream& out, const Card& c) {
    switch (c.getValue()) {
        case 2:
            out << "2";
            break;
        case 3:
            out << "3";
            break;
        case 4:
            out << "4";
            break;
        case 5:
            out << "5";
            break;
        case 6:
            out << "6";
            break;
        case 7:
            out << "7";
            break;
        case 8:
            out << "8";
            break;
        case 9:
            out << "9";
            break;
        case 10:
            out << "10";
            break;
        case 11:
            out << "Jack";
            break;
        case 12:
            out << "Queen";
            break;
        case 13:
            out << "King";
            break;
        case 14:
            out << "Ace";
            break;
    }

    switch (c.getSuit()) {
        case Suit::Hearts:
            out << " of Hearts";
            break;
        case Suit::Diamonds:
            out << " of Diamonds";
            break;
        case Suit::Clubs:
            out << " of Clubs";
            break;
        case Suit::Spades:
            out << " of Spades";
            break;
    }
    
    return out;
}
