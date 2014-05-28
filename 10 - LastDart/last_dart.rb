# 
#  last_dart.rb
#  LastDart
#
# Created by Muhammad Hussein Nasrollahpour on 5/26/14
# Copyright (c) 2014 Chocolate. All rights reserved.
#



input = File.open("./last_dart_input.txt", "r")

row_and_column = input.first

val_of_row_column = row_and_column.split ' '

number_of_rows = val_of_row_column[0].to_i
number_of_columns = val_of_row_column[1].to_i

# keeps the index of each value
index_of_each_value = []

# Keeps the index of the row
row_idx = 0

input.each_line do |line|
  values = line.split ' '

  0.upto(values.count - 1).each do |column_idx|
    index_of_each_value.push({ :value => values[column_idx], :row => row_idx, :column => column_idx })
  end

  row_idx += 1
end

values = []

index_of_each_value.each do |idx|
  values.push idx[:value].to_i
end

values.sort!

# Keeps the maximum element inside values
max = values[values.count - 1]

# Maximum element row index
row_idx = 0
# Maximum element column index
column_idx = 0

index_of_each_value.each do |idx|
  if max == idx[:value].to_i
    row_idx = idx[:row]
    column_idx = idx[:column]
  end
end

print row_idx + 1, " ", column_idx + 1, "\n"
