//
// Created by Elisabeth Kollrack on 9/27/24.
//

/**
 * WAR MAIN PROGRAM
 */

#include "Deck.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


const string python = "python3";

int get_int_from_user();
char get_char_from_user();
string play_war(vector<Card>& player1_hand, vector<Card>& computer_hand, int& player1_wins, 
                int& computer_wins, int& rounds, ofstream& file, int& player1_wars_won, int& computer_wars_won);
void war_stats(int& player1_wins, int& computer_wins, int& rounds, const string& file, int& player1_wars_won, int& computer_wars_won, 
              int& player1_games_won, int& computer_games_won);
void write_to_file(ofstream& file,vector<Card>& player1_hand, vector<Card>& computer_hand, int& rounds);

int main(int argc, char* argv[]) {

  cout << ("*******************************************************") << endl;
  cout << "\t\t\t\t   WELCOME TO WAR" << endl;
  cout << ("*******************************************************") << endl;

  // asks the user if they want to play
  char choice = get_char_from_user();


  if (choice == 'q') {
    cout << "See ya! " << endl;
  }

  // the user entered 'p'
  else if (choice == 'p'){

    int game_number = get_int_from_user();
    int player1_games_won = 0;
    int computer_games_won = 0;

    for (int game = 1; game <= game_number; ++game) {
      cout << "\n***Game " << game << "***" << endl;

      // create a deck of cards and shuffle it - new deck for each round
      Deck deck;
      deck.shuffle();
      // create a hand for each player
      vector<Card> player1_hand;
      vector<Card> computer_hand;

      // Deal 26 cards alternately to each player
      for (int i = 0; i < 26; i++) {
        player1_hand.push_back(deck.deal_card());
        computer_hand.push_back(deck.deal_card());
      }

      // stats to keep track of
      int player1_wins = 0;
      int computer_wins = 0;
      int rounds = 0;
      int player1_wars_won = 0;
      int computer_wars_won = 0;

      // file for hand counts that I'll use for graphing
      ofstream file("hand_count.csv");
      file << "Round,Player 1 Hand Size,Computer Hand Size\n"; 

      // play the game and print the result
      string result = play_war(player1_hand, computer_hand, player1_wins, computer_wins, rounds, file,player1_wars_won, computer_wars_won);
      cout << result << endl;

      if (result == "Player 1 doesn't have enough cards for a war. Computer wins!!!!" ||
          result == "Computer wins!!") {
        cout << "Computer wins game " << game << "!" << endl;
        computer_games_won++;

      } 
      else if (result == "Computer doesn't have enough cards for a war. Player 1 wins!!!!" || 
                result == "Player 1 wins!!") {
        cout << "Player 1 wins game " << game << "!" << endl;
        player1_games_won++;
      }
      
      war_stats(player1_wins, computer_wins, rounds, "hand_count.csv", player1_wars_won, computer_wars_won, player1_games_won, computer_games_won);
      

      file.close();
    }
  }
  return 0;
}



// Inputs: N/A
// Effects: Repeatedly prompts the user for an integer until a valid integer is received
// Returns: A valid integer from the user
int get_int_from_user() {

    string userInput;
    int num;
    // Valid checks to see if the user has entered good input
    bool valid = false;
    stringstream ss;

    cout << "How many games would you like to play? ";
    getline(cin,userInput);
    ss << userInput;

    while (!valid) {
        for (int i = 0; i < (userInput.length()); i++) {
            if (isspace(userInput[i])) {
                cout << "Invalid input. Enter an integer: ";
                getline(cin, userInput);
                ss.str("");
                ss.clear();
                ss << userInput;
                // Reset i to -1, so it will be zero again for the next iteration
                i = -1;
            }

            // Check to see if the user entered a float
            else if (userInput[i] == '.') {
                cout << "Invalid input. Enter an integer: ";
                getline(cin, userInput);
                ss.str("");
                ss.clear();
                ss << userInput;
                // Reset i to -1, so it will be zero again for the next iteration
                i = -1;
            }
        }

        if (userInput.length() == 0) {
            cout << "No input. Enter an integer: ";
            getline(cin,userInput);
            ss.str("");
            ss.clear();
            ss << userInput;
        }

        else if (ss >> num) {
            char remaining;
            // Looks for extra characters b/c stringstream reads until
            // it reaches an invalid character
            if (ss >> remaining) {
                cout << "Invalid input. Enter an integer: ";
                getline(cin,userInput);
                ss.str("");
                ss.clear();
                ss << userInput;
            }

            else {
                valid = true;
            }
        }

        // In case any flags missed
        else {
            cout << "Invalid input. Enter a number: ";
            getline(cin, userInput);
            ss.str("");
            ss.clear();
            ss << userInput;
        }
    }
    return num;
}

// Inputs: N/A
// Effects: Repeatedly prompts the user for an integer until a 'q' or 'p' is received
// Returns: Either 'q' to quit or 'p' to play
char get_char_from_user() {

  string userInput;
  cout << "Enter (p) to play and (q) to quit: ";
  getline(cin,userInput);

  bool valid = false;
  // checks for a valid character
  while (!valid) {
    if (userInput.length() != 1) {
      cout << "Invalid input. Enter a single character: ";
      getline(cin,userInput);
    }

    else if (std::tolower(userInput[0]) != 'q' && std::tolower(userInput[0]) != 'p') {
      cout << "Invalid character. Enter (p) to play and (q) to quit: ";
      getline(cin,userInput);
    }
    else {
      valid = true;
    }
  }
  return userInput[0];
}


// Inputs: Each player's vector of cards
// Effects: Plays the card game "war" until a player is out of cards
// Returns: A string describing the winner
string play_war(vector<Card>& player1_hand, vector<Card>& computer_hand, int& player1_wins, 
                int& computer_wins, int& rounds, ofstream& file, int& player1_wars_won, int& computer_wars_won) {

  while (!player1_hand.empty() && !computer_hand.empty()) {
    rounds++;
    write_to_file(file, player1_hand,computer_hand, rounds);

    // deal from the top of the deck
    Card player1_card = player1_hand[0];
    Card computer_card = computer_hand[0];

    cout << "Player 1's card: " << player1_card.print_card() << endl;
    cout << "Computer's card: " << computer_card.print_card() << endl;

    // erases the top card from the player's hand
    player1_hand.erase(player1_hand.begin());
    computer_hand.erase(computer_hand.begin());

    if (player1_card.get_rank() > computer_card.get_rank()) {
      cout << "Player 1 wins the round!" << endl;
      player1_wins++;
      // add both cards to the winner player's deck
      player1_hand.push_back(player1_card);
      player1_hand.push_back(computer_card);
    }
    else if (player1_card.get_rank() < computer_card.get_rank()) {
      cout << "Computer wins the round!" << endl;
      computer_wins++;
      // add both cards to the winner player's deck
      computer_hand.push_back(player1_card);
      computer_hand.push_back(computer_card);
    }

    // WAR
    else {
      // create a new vector to put all the cards in the war
      vector<Card> war_pile;
      war_pile.push_back(player1_card);
      war_pile.push_back(computer_card);

      // in case there are multiple wars
      bool war_winner = false;

      while (!war_winner) {
        cout << "WAR" << endl;

        // make sure players have enough cards for a war
        if (player1_hand.size() < 4 || computer_hand.size() < 4) {
          if (player1_hand.size() < 4) {
            computer_wins++;
            return "Player 1 doesn't have enough cards for a war. Computer wins!!!!";
          }
          else {
            player1_wins++;
            return "Computer doesn't have enough cards for a war. Player 1 wins!!!!";
          }
        }


        for (int i = 0; i < 3; ++i) {
          // add 3 cards for each player to the war pile and remove the cards from the player's hands
          war_pile.push_back(player1_hand[i]);
          player1_hand.erase(player1_hand.begin());
          war_pile.push_back(computer_hand[i]);
          computer_hand.erase(computer_hand.begin());
        }

        // play the top card face up
        Card player1_war_card = player1_hand[0];
        Card computer_war_card = computer_hand[0];
        player1_hand.erase(player1_hand.begin());
        computer_hand.erase(computer_hand.begin());

        cout << "Player 1's top card: " << player1_war_card.print_card() << endl;
        cout << "Computer's top card: " << computer_war_card.print_card() << endl;

        war_pile.push_back(player1_war_card);
        war_pile.push_back(computer_war_card);

        if (player1_war_card.get_rank() > computer_war_card.get_rank()) {
          cout << "Player 1 wins the WAR!!!" << endl;
          player1_wars_won++;
          player1_wins++;
          // add the war pile to player 1's hand
          player1_hand.insert(player1_hand.end(), war_pile.begin(), war_pile.end());
          war_winner = true;
        }
        else if (player1_war_card.get_rank() < computer_war_card.get_rank()) {
          cout << "Computer wins the WAR!!!" << endl;
          computer_wars_won++;
          computer_wins++;
          // add the war pile to computer's hand
          computer_hand.insert(computer_hand.end(), war_pile.begin(), war_pile.end());
          war_winner = true;
        }
        else {
          cout << "ANOTHER WAR!!" << endl;
        }
      }
    }

    // check if the players still have cards
    if (player1_hand.empty()) {
      return "Computer wins!!";
    }
    if (computer_hand.empty()) {
      return "Player 1 wins!!";
    }
    
  }
  return "Game ended unexpectedly. No winner:(";
}

// Inputs: Player wins, computer wins, rounds, a filename to hold stats, and wars won
// Effects: Writes information from the game to Python
// Returns: N/A
void war_stats(int& player1_wins, int& computer_wins, int& rounds, const string& file, int& player1_wars_won, int& computer_wars_won, int& player1_games_won, int& computer_games_won ) {
    string command = python + " stats.py " + 
                     to_string(player1_wins) + " " + 
                     to_string(computer_wins) + " " + 
                     to_string(rounds) + " " + file + " " +
                     to_string(player1_wars_won) + " " + to_string(computer_wars_won) + " " +
                     to_string(player1_games_won) + " " + to_string(computer_games_won);
    
    system(command.c_str());
}

// Inputs: File to write to, hand sizes, and rounds
// Effects: Writes information about hand counts to a csv file to be used for graphing
// Returns: N/A
void write_to_file(ofstream& file, vector<Card>& player1_hand, vector<Card>& computer_hand, int& rounds) {
  file << rounds << "," << player1_hand.size() << "," 
        << computer_hand.size() << endl;
}




