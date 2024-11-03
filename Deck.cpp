//
// Created by Elisabeth Kollrack on 9/27/24.
//

#include "Deck.h"

Deck::Deck() : card_index(0) {
    // set size of vector
    cards.reserve(NUMBER_OF_CARDS);
    for (int value = 2; value <= 14; value++) {
        cards.push_back(Card(value, Card::Suit::CLUBS));
        cards.push_back(Card(value, Card::Suit::DIAMONDS));
        cards.push_back(Card(value, Card::Suit::HEARTS));
        cards.push_back(Card(value, Card::Suit::SPADES));
    }
}

const vector<Card>& Deck::get_cards() {
    return cards;
}

Card Deck::deal_card() {
    return(cards[card_index++]);
}

void Deck::shuffle() {
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(),g);
}

