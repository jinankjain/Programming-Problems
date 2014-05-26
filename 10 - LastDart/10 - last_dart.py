#
#  last_dart.py
#  LastDart
#
# Created by Muhammad Hussein Nasrollahpour on 5/26/14
# Copyright (c) 2014 Chocolate. All rights reserved.
#

# input = open("./last_dart_input.txt", "r")

# keeps the index of each value
index_of_each_value = []

# Keeps the index of the row
row_idx = 0

index_of_each_value = []

for line in input:
  values = line.split()

  for column_idx in range(len(values)):
    value_and_its_idx = { 'value' : values[column_idx], 'row' : row_idx, 'column' : column_idx + 1 }

    index_of_each_value.append(value_and_its_idx)

  row_idx += 1

values = []
for idx in index_of_each_value:
  values.append(int(idx['value']))


values.sort()

max = values[len(values) - 1]

# Maximum element row index
row_idx = 0
# Maximum element column index
column_idx = 0

for idx in index_of_each_value:
  if max == int(idx['value']):
    print idx['value']
    row_idx = idx['row']
    column_idx = idx['column']


print row_idx , " ", column_idx
