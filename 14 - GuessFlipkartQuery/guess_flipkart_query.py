#
#  guess_flipkart_query.py
#  GuessFilpkartQuery
#
#  Created by Muhammad Hussein Nasrollahpour on 5/30/14
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

from sys import stdout
import fileinput

# Keeps the content of input file
# input = open('./input.txt', 'r')
input = fileinput.input()

# Keeps the number of products
N = input.readline()

# Keeps search queries
search_queries = [
'axe deo',
'best-seller books',
'calvin klein',
'camcorder',
'camera',
'chemistry',
'chromebook',
'c programming',
'data structures algorithms',
'dell laptops',
'dslr canon',
'mathematics',
'nike-deodrant',
'physics',
'sony cybershot',
'spoken english',
'timex watch',
'titan watch',
'tommy watch',
'written english',
]

# finds a response to search query.
def find(line):
  # Separate the line in order to get all words in that line.
  separate_line = line.split()

  is_written_english = True

  # Walk through search queries list in order to give the best result
  # that matches a query.
  for search_query in search_queries:

    # Separate the search query in order to get all words in it.
    separate_search_query = search_query.split()

    # Walk through all search query and line words to find a match.
    for word_in_search_query in separate_search_query:
      for word_in_line in separate_line:
        # Strip some useless punctuation
        word = word_in_line.strip(':')

        # if both words are equal then write the search query to output
        if word_in_search_query == word.lower():
          stdout.write(search_query + '\n')
          is_written_english = False
          return

  if is_written_english:
    stdout.write(search_queries[19] + '\n')

# Reads the content of input [file] line by line
# and finds the response to each search query.
for line in input:
  find(line)
