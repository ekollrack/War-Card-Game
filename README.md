# War Program in C++

## Author: Elisabeth Kollrack

## Overview

This project is a digital version of the card game "War," implemented in **C++** with data visualization in **Python**. The program simulates the simple two-player game, where each player starts with half of a shuffled deck, and rounds are played based on the highest card value. The program logs each round’s results and provides post-game statistics, including graphs and tables of game outcomes, in a **hand_counts.csv** file.

A **Python** script processes this data, creating tables and graphs to visualize the game’s progression and outcomes, offering insights into the number of cards each player holds per round.

## Project Components

### 1. **Game Mechanics (C++)**
The deck is shuffled and each player takes half the deck. Then they each play their top card, face up, and the player with the highest card value (suits don't matter) takes both cards into their "pile," and this process continues. If the players play the same value card, it is called a "War." The players then each place 3 cards face down and 1 card face up. The player with the higher face up card takes all the cards. The goal of the game is for one player to run out of cards, which would make the other player win. My program replicates this card game.

### 2. **Data Logging (C++)**
   - **Round Data Export**: Each round’s card counts are logged in `hand_counts.csv` to track how many cards each player holds throughout the game.

### 3. **Data Analysis and Visualization (Python)**
The Python script reads `hand_counts.csv`, processes round statistics, and generates visual outputs. **Matplotlib** is used to create graphs showing trends in card counts across rounds. Summary tables are then displayed using **Tabulate** for key game metrics.


#### Installations:
Python:

sys, csv, matplotlib, numpy, tabulate

### Usage
1. **Compile and Run C++ Code**: Compile the `main.cpp` file and execute to play the game. 
2. **CSV Generation**: `main.cpp` will create `hand_counts.csv` after each game.
3. **Run Python Visualization**: C++ will call Python, which will print the game statistics and graphs. 

## Languages

- **C++**: Handles the game mechanics, deck and card logic, and data logging.
- **Python**: Processes game data for analysis and visualization.

## Sources

   
| **Topic**                   | **Source**                                                                                             |
|-----------------------------|--------------------------------------------------------------------------------------------------------|
| `vector::reserve`      | [Stack Overflow](https://stackoverflow.com/questions/11457571/how-to-set-initial-size-of-stdvector)    |
| Switch Statements           | [Stack Overflow](https://stackoverflow.com/questions/57921142/using-switch-case-statement-to-pull...) |
| `to_string`            | [Simplilearn](https://www.simplilearn.com/tutorials/cpp-tutorial/int-to-string-cpp)                    |
| Random Generation           | [Stack Overflow](https://stackoverflow.com/questions/38367976/do-stdrandom-device-and-stdmt19937...)   |
| `tolower` Functionality     | [Stack Overflow](https://stackoverflow.com/questions/33849637/convert-a-single-character-to-lower...)  |
| Clearing a Vector           | [GeeksforGeeks](https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/)                         |
| Vector Insert/Begin/End     | [GeeksforGeeks](https://www.geeksforgeeks.org/vector-insert-function-in-cpp-stl/)                      |
| Checking if Vector is Empty | [TutorialsPoint](https://www.tutorialspoint.com/cpp_standard_library/cpp_vector_empty.htm)             |
| Appending to File           | [Stack Overflow](https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c)   |
| Skipping CSV Headers        | [Stack Overflow](https://stackoverflow.com/questions/14257373/how-to-skip-the-headers-when-processing) |
| CSV Module                  | [UVM PDF](https://www.uvm.edu/~cbcafier/itpacs/itpacs_cafiero.pdf)                                     |
| Matplotlib Cheatsheet       | [Matplotlib](https://matplotlib.org/cheatsheets/_images/cheatsheets-1.png)                             |
| Tabulate Package            | [DataCamp](https://www.datacamp.com/tutorial/python-tabulate)                                          |



