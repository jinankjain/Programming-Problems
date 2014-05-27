#
#  single_elimination.py
#  SingleElimination
#
#  Created by Muhammad Hussein Nasrollahpour on 5/27/14
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

# Contains the content of input file
input = open("./input.txt", "r")

# Keeps all teams in the match
all_teams = []

# Keeps all loser in all games
losers = []

# Keeps the winner
winner = None

# Keeps the result of algorithm
with open("./output.txt", "w") as output:

  # Keeps the number of players
  N = input.readline()


  # Iterates through contents of input file to eliminate loser
  for line in input:

    # Split the content of the line by space
    two_teams_in_match = line.split()

    # Keeps the first and second team
    winner = two_teams_in_match[0]
    loser = two_teams_in_match[1]

    # Add all losers to the list
    losers.append(loser)

    # Sees whether or not a team is inserted as one team in list or not
    # And if that team is not in list yet add it to the list
    if not winner in all_teams:
      all_teams.append(winner)
    if not loser in all_teams:
      all_teams.append(loser)

  # Just removes all losers from all teams to get the winner
  for item in losers:
    all_teams.remove(item)

  # Write the winner to the output
  # all_teams[0] is the only item in the list
  # and as it turns out it's the winner too.
  output.write(all_teams[0])

  # Print the winner to the output
  print all_teams[0]
