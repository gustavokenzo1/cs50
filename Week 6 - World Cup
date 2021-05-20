# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    # Open file user typed in command line to read it
    with open(sys.argv[1], "r") as file:
        
        # Read each row
        reader = csv.DictReader(file)
        
        # Append rows team and rating to teams[] while also transforming rating into an int
        for row in reader:
            row["team"]
            row["rating"] = int(row["rating"])
            teams.append(row)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    
    # Loop starting from 0, go to N - 1, with increments of 1. 2nd arg is exclusive, but we are
    # counting from 0 and not from 1, so (0, N] = (0, N - 1)
    for i in range(0, N, 1):
        
        # Call function simulate_tournament N times for the winner and increment their total
        won = simulate_tournament(teams)
        if won in counts:
            counts[won] += 1
            
        else:
            counts[won] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    
    # TODO
    # While there are 2 or more teams still in the tournament, call function simulate_round with
    # those teams, select winners and return them
    if len(teams) >= 2:
        winner = simulate_round(teams)
        return simulate_tournament(winner)
    
    # When there is only 1 team left, they are the winners
    else:
        won = teams[0]["team"]
        return won
        
        
if __name__ == "__main__":
    main()
