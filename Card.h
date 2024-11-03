//
// Created by Elisabeth Kollrack on 9/28/24.
//

#ifndef M2OEP_CARD_H
#define M2OEP_CARD_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;



class Card {
public:
    // Suit as an enumerated type
    enum Suit {CLUBS,DIAMONDS, HEARTS, SPADES};

    /**
     * Requires: rank and suit
     * Modifies: rank, suit
     * Effects: adds cards
     */
    Card(int rank, Suit suit);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the rank of the card
    */
    int get_rank() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the suit of the card
     */
    Suit get_suit() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints card
    */
    string print_card() const;

    /* Overloaded operator for printing a card */
    friend ostream& operator << (ostream& outs, const Card& q);


protected:
    int rank;
    Suit suit;

};


#endif //M2OEP_CARD_H
