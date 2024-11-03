//
// Created by Elisabeth Kollrack on 9/30/24.
//

#include "Deck.h"
#include <iostream>
using namespace std;

bool test_card();
bool test_deck();

int main() {
    if (test_card()) {
        cout << "Passed all Card test cases" << endl;
    }
    if (test_deck()) {
        cout << "Passed all Deck test cases" << endl;
    }
    return 0;
}

bool test_card() {
    bool passed = true;

    // creates a 2 of clubs card
    Card c1(2,Card::CLUBS);

    if (c1.get_rank() != 2) {
        passed = false;
        cout << "FAILED getRank test: expected 2, got " << c1.get_rank() << endl;
    }
    if (c1.get_suit() != Card::CLUBS) {
        passed = false;
        cout << "FAILED getSuit test: expected CLUBS, got " << c1.get_suit() << endl;
    }
    if (c1.print_card() != "2 of Clubs") {
        passed = false;
        cout << "FAILED printCard test: expected '2 of Clubs' got " << c1.print_card()<< endl;
    }

    // creates a face card, jack of hearts
    Card c2(11, Card::HEARTS);
    if (c2.get_rank() != 11) {
        passed = false;
        cout << "FAILED getRank test: expected 11, got " << c2.get_rank() << endl;
    }
    if (c2.get_suit() != Card::HEARTS) {
        passed = false;
        cout << "FAILED getSuit test: expected CLUBS, got " << c2.get_suit() << endl;
    }
    if (c2.print_card() != "Jack of Hearts") {
        passed = false;
        cout << "FAILED printCard test: expected 'Jack of Hearts' got " << c2.print_card()<< endl;
    }

    // test ace
    Card c3(14,Card::DIAMONDS);
    if (c3.get_rank() != 14) {
        passed = false;
        cout << "FAILED getRank test: expected 14, got " << c3.get_rank() << endl;
    }
    if (c3.get_suit() != Card::DIAMONDS) {
        passed = false;
        cout << "FAILED getSuit test: expected DIAMONDS, got " << c3.get_suit() << endl;
    }
    if (c3.print_card() != "Ace of Diamonds") {
        passed = false;
        cout << "FAILED printCard test: expected 'Ace of Diamonds', got " << c3.print_card() << endl;
    }
    return passed;
}

bool test_deck() {
    bool passed = true;
    Deck d1;
    if (d1.get_cards().size() != 52) {
        passed = false;
        cout << "FAILED deck size test: expected 52, got " << d1.get_cards().size() << endl;
    }

    // make sure the total deck always has 52 cards
    d1.deal_card();
    if (d1.get_cards().size() != 52) {
        passed = false;
        cout << "FAILED deck size after deal test: expected size to remain 52 (cards are not removed), got " << d1.get_cards().size() << endl;
    }

    // make sure first card of unshuffled deck is 2 of clubs
    Deck d2;
    Card first_card = d2.deal_card();
    if (first_card.get_rank() != 2 || first_card.get_suit() != Card::CLUBS) {
        passed = false;
        cout << "FAILED dealCard test: expected 2 of Clubs, got " << first_card.print_card() << endl;
    }

    // test shuffle
    Deck d3;
    d3.shuffle();

    Card top_of_deck = d3.deal_card();
    Card second_card = d3.deal_card();
    // see if first two cards are the same
    if (top_of_deck.print_card() == "2 of Clubs" || second_card.print_card() == "2 of Diamonds") {
        passed = false;
        cout << "FAILED shuffle test: deck did not shuffle" << endl;
    }

    return passed;
}