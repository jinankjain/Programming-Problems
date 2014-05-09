# pattern_matching_problem.rb
# PatternMatching
#
# Created by Muhammad Hussein Nasrollahpour on 5/8/14
# Copyright (c) 2014 Chocolate. All rights reserved.
#


pattern = ARGV[0].dup
text = ARGV[1].dup

p_len = pattern.length

occurrence = false

puts text

text.each_char do |char|
	temp = text[text.index(char)+(p_len-1)]
	
	if temp == pattern[p_len - 1]
		temp_str = text[text.index(char)...p_len]

		p_idx = 0
		t_idx = text.index(char)
		temp_str.each_char do |c|
			tc = text[text.index(char)]
			if pattern[p_idx] == text[t_idx]
				occurrence = true
				
			else
				occurrence = false
			end

			p_idx += 1
			t_idx += 1
		end
	end

	if occurrence
		puts "#{pattern} found" 
	else
		text = text[(text.index(char) + 1)..(text.length - 1)]
		puts text
	end
	
	occurrence = false
end
