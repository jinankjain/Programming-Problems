#
#  pyramid_organization.rb
#  PyramidOrganization
#
#  Created by Muhammad Hussein Nasrollahpour on 4/26/14.
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

class Person
  def initialize
    @months_in_system = 1
  end

  def dead?
    @months_in_system >= 3
  end

  def next_month
    @months_in_system += 1
  end
end

number_of_months = ARGV[0].to_i

people = [Person.new]

1.upto(number_of_months).each do |month|
  people_left = people.count(&:dead?)
  people.reject!(&:dead?)
  people.each(&:next_month)
  people.concat Array.new(people.size) { Person.new }

  puts "#{people.size} people in the system after #{month} month(s), #{people_left} person[s] have left."
end
