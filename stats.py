"""
Elisabeth Kollrack 
M3OEP Python
Used Python to create tables and graphs from the WAR game
"""

import sys
import csv
import matplotlib.pyplot as plt
import numpy as np
from tabulate import tabulate



"""
Function plot_war_stats graphs the hand counts for both players throughout the game
"""
def plot_war_stats(filename):
    rounds = [];
    player1_hands = [];
    computer_hands = [];

    with open('hand_count.csv','r') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)
        for row in reader:
            rounds.append(int(row[0]))
            player1_hands.append(int(row[1]))
            computer_hands.append(int(row[2]))

    plt.plot(rounds,player1_hands, color = 'red', label = "Player 1 Hand Size")
    plt.plot(rounds,computer_hands, color = 'blue', label = "Computer Hand Size")

    plt.title('War Hand Size Tracker')
    plt.xlabel('Rounds')
    plt.ylabel('Hand Size')
    ticks = max(rounds) //  14    # make sure ticks are readable
    plt.xticks(np.arange(0, max(rounds) + 5, step=ticks))
    plt.legend()
    plt.show()


"""
Function print_table prints a table of some game stats including wins, round count, win difference, and wars won
This prints after each round
"""
def print_table(player1_wins, computer_wins, rounds, win_diff, player_wars_won, computer_wars_won, total_games):
    table = [
        ["Player Wins", "Computer Wins", "Rounds", "Win Difference", "Player Wars Won", "Computer Wars Won"],
        [player1_wins, computer_wins, rounds, win_diff, player_wars_won, computer_wars_won]
    ]
    print(f"***Game {total_games} Stats***")
    print(tabulate(table, headers='firstrow', tablefmt='fancy_grid'))

"""
Function print_tournament_table prints the summary table of the entire tournament
Prints after each round
"""
def print_tournament_table(player_games_won, computer_games_won,total_games):
    table = [
        ["Total Games","Player Games Won", "Computer Games Won"],
        [total_games, player_games_won, computer_games_won]
    ]
    print(f'***Tournament Scorecard***')
    print(tabulate(table, headers="firstrow", tablefmt='fancy_grid'))
    

if __name__ == "__main__":
    # Information from c++ file
    player1_wins = int(sys.argv[1])
    computer_wins = int(sys.argv[2])
    rounds = int(sys.argv[3])
    win_diff = abs(player1_wins - computer_wins)
    filename = sys.argv[4]
    player_wars_won = int(sys.argv[5])
    computer_wars_won = int(sys.argv[6])
    player_games_won = int(sys.argv[7])
    computer_games_won = int(sys.argv[8])
    total_games = player_games_won + computer_games_won

    # Function calls
    plot_war_stats(filename)
    print_table(player1_wins, computer_wins, rounds, win_diff, player_wars_won, computer_wars_won, total_games)
    print_tournament_table(player_games_won, computer_games_won, total_games)
    

