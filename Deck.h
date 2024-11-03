//
// Created by Elisabeth Kollrack on 9/27/24.
//

#ifndef M2OEP_DECK_H
#define M2OEP_DECK_H
#include "Card.h"
#include <vector>
#include <random>

using namespace std;


class Deck {

public:
    /**
     * Requires: nothing
     * Modifies: cards_left
     * Effects: adds cards to the deck
     */
    Deck();
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: a reference to vector of cards
    */
     const vector<Card>& get_cards();
    /**
     * Requires: nothing
     * Modifies: cards_left
     * Effects: deals a card
     */
    Card deal_card();

    /**
     * Requires: nothing
     * Modifies: vector of cards
     * Effects: shuffles the deck
     */
    void shuffle();


    static const int NUMBER_OF_CARDS = 52;

protected:
    int card_index;

private:
    vector <Card> cards;

};


#endif //M2OEP_DECK_H
