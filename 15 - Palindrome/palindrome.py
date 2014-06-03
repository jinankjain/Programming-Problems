#
#  palindrome.py
#  Palindrome
#
#  Created by Muhammad Hussein Nasrollahpour on 6/3/14
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

from sys import stdout
import fileinput

# Contains the content of input.
input = fileinput.input()
# input = open('./input.txt', 'r')

# Keeps the number of test cases.
T = int(input.readline())

# Determines whether the word is already in palindrome form or not
# and returns the index of a character if that character
# is invalid(doesn't match with other character in comparison)
def is_palindrome(word):

  # Strip some unwanted character such as new ling \n
  word = line.strip()

  # Keeps length of the word.
  # Will be used to access the character of word from end of it.
  length = len(word)

  # Return -1 if word is already in palindrome form
  if word == word[::-1]:
    return -1

  # If the word is not in palindrome form go to see which character[s] cause[s] it.
  for idx in range(len(word)):

    length -= 1

    if word[idx] != word[length]:
      # Here we've found the index of the character that causes the problem
      # but we should test it to see if we remove the character
      # could we obtain the palindrome form.

      temp_word = list(word)
      temp_word.pop(idx)
      ''.join(temp_word)

      if temp_word == temp_word[::-1]:
        return idx

# Walk through content of the input
for line in input:
  # Write the result to the standard output
  stdout.write(str(is_palindrome(line)) + '\n')
