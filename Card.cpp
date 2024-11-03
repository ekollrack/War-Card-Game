//
// Created by Elisabeth Kollrack on 9/28/24.
//

#include "Card.h"


Card::Card(int rank, Suit suit) : rank(rank), suit(suit)  {

}

int Card::get_rank() const {
    return rank;
}

Card::Suit Card::get_suit() const {
    return suit;
}


string Card::print_card() const {
    string rank_as_string;
    // uses switch to convert face cards
    switch(rank) {
        case 11: rank_as_string = "Jack";
            break;
        case 12: rank_as_string = "Queen";
            break;
        case 13: rank_as_string = "King";
            break;
        case 14: rank_as_string = "Ace";
            break;
        default: rank_as_string = std::to_string(rank);
    }

    string suit_as_string;
    switch (suit) {
        case CLUBS: suit_as_string = "Clubs";
        break;
        case DIAMONDS: suit_as_string = "Diamonds";
            break;
        case HEARTS: suit_as_string = "Hearts";
            break;
        case SPADES: suit_as_string = "Spades";
            break;
    }

    return rank_as_string + " of " + suit_as_string;
}

ostream& operator << (ostream& outs, const Card& card) {
    outs << card.print_card();
    return outs;
}

