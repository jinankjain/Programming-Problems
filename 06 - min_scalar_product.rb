#
#  min_scalar_product.rb
#  MinimumScalarProduct
#
#  Created by Muhammad Hussein Nasrollahpour on 10/4/14.
#  Copyright (c) 2014 Chocolate. All rights reserved.
#


 input = File.open("/Users/muhammad/Desktop/in.txt", "r")
 output = File.open("/Users/muhammad/Desktop/out.txt", "w")

 T = input.first

 lock = 1
 n = 0
 v1 = []
 v2 = []
 product = []
 sum = 0

 _case = 1

 input.each_line do |line|
   if 1 == lock
     n = Integer line
   elsif 2 == lock
     tempV1 = line.split " "
     tempV1.each do |str|
       value = Integer str
       v1.push value
     end
   elsif 3 == lock
     tempV2 = line.split " "
     tempV2.each do |str|
       value = Integer str
       v2.push value
     end
   end

   lock += 1

   if lock >= 4
     lock = 1

     v1.sort!
     v2.sort!.reverse!

     for idx in 0...n
       mul = v1[idx] * v2[idx]
       product.push mul
     end

     product.each do |value|
       sum += value
     end

     result = "Case ##{_case}: #{sum} \n"

     output.write result

     n = 0
     v1 = []
     v2 = []
     product = []
     sum = 0

     _case += 1
   end

 end
