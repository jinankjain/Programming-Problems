#
#  crush.rb
#  Algorithmic Crush
#
#  Created by Muhammad Hussein Nasrollahpour on 6/4/14
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

input = ARGF.read.split "\n"

# Size of list.
N = Integer input[0].split(" ")[0]
# Number of queries that we perfom on the list to get the max element.
M = Integer input[0].split(" ")[1]

numbers = Array.new(N, 0)

input.delete_at 0

input.each do |line|

  a = Integer(line.split(" ")[0]) - 1
  b = Integer(line.split(" ")[1]) - 1
  k = Integer(line.split(" ")[2])

  a.upto(b) do |idx|
    numbers[idx] = numbers[idx] + k
  end

end

numbers.sort!

puts numbers[numbers.count - 1]
