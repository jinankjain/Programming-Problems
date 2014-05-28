#
#  stack_of_paper.py
#  StackofPaper
#
#  Created by Muhammad Hussein Nasrollahpour on 5/28/14
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

# Contains the content of input file
input = open("./input.txt", "r")

# Keeps the number of sheets of paper
N = input.readline();

# Keeps all width and height
all_width_height = []

# The result will be written in output file
with open("./output.txt", "w") as output:

  # Walk through input file in order to get width & height of papers
  for line in input:

    # split the content of the line because width and height values are seperated by a space
    width_and_height = line.split()

    # Contains width and height value
    width = int(width_and_height[0])
    height = int(width_and_height[1])

    # Rotates sheet if height is greater than width
    if height > width:
      temp = width
      width = height
      height = temp

    all_width_height.append([width, height])

  all_width_height.sort()

  for w_h in reversed(all_width_height):
    output.write(str(w_h[0]) + ' ')
    output.write(str(w_h[1]))
    output.write('\n')
