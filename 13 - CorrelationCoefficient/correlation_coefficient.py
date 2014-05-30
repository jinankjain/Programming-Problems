#
#  correlation_coefficient.py
#  CorrelationCoefficient
#
#  Created by Muhammad Hussein Nasrollahpour on 5/30/14
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

from math import sqrt
from sys import stdout, stdin
import fileinput

# Contains the input data.
# input = open('./input.txt', 'r')
input = fileinput.input()

# Keeps the number of students.
N = int(input.readline())

# Keeps all scores.
scores = []

# Keeps sum of production of mathematics and physics.
m_p = 0

# Keeps sum of producation of physics and chemistry.
p_c = 0

# Keeps the producation of mathematics and chemistry.
m_c = 0

# Keeps sum of mathematics scores.
m_sum = 0
# Keeps sum of square of mathematics scores.
mm_sum = 0

# Keeps sum of physics scores.
p_sum = 0
# Keeps sum of square of physics scores.
pp_sum = 0

# Keeps sum of chemistry.
c_sum = 0
# Keeps sum of square of chemistry scores.
cc_sum = 0

SSMathematics = 0
SSPhysics = 0
SSChemistry = 0

SSCPMathematics_Physics = 0
SSCPPhysics_Chemistry = 0
SSCPMathematics_Chemistry = 0

# Keeps correlation coefficient of Mathematics and Physics
r1 = 0
# Keeps correlation coefficient of Physics and Chemistry
r2 = 0
# Keeps correlation coefficient of Mathematics and Chemistry
r3 = 0

# Write the three correlation coefficients.
with open('./output.txt', 'w') as output:

  # Reads the content of file line by line to gather
  # all candidate's scores in Mathematic, Physic, and Chemistry.
  for line in input:
    # Each line contains three values separated by space.
    # So split the line by space to get all three values.
    # m, p, and c denote mathematics, physics, and chemistry respectively.
    m_p_c = line.split()

    # Put all these scores into a list.
    # Definitely need all of them to compute our correlation.
    scores.append({ 'm':m_p_c[0], 'p':m_p_c[1], 'c':m_p_c[2] })

  for data in scores:
    # Get the value of each score and then cast it.
    m = int(data['m'])
    p = int(data['p'])
    c = int(data['c'])

    # Compute sum of mathematics, physics, chemistry scores
    m_sum += m
    p_sum += p
    c_sum += c

    # Compute sume of square of mathematics, physics, chemistry scores
    mm_sum += m ** 2
    pp_sum += p ** 2
    cc_sum += c ** 2

    # Calculate sum of production of mathematics and physics.
    m_p += m * p
    # Calculate sum of production of physics and chemistry.
    p_c += p * c
    # Calculate sum of production of mathematics and chemistry.
    m_c += m * c

  # Calculate SSMathematics
  SSMathematics = mm_sum - (m_sum ** 2 / N)

  # Calculate SSPhysics
  SSPhysics = pp_sum - (p_sum ** 2 / N)

  # Calculate SSChemistry
  SSChemistry = cc_sum - (c_sum ** 2 / N)

  # Calculate SSCP for mathematics and physics
  SSCPMathematics_Physics = m_p - ((m_sum * p_sum) / N)

  # Calculate SSCP for physics and chemistry
  SSCPPhysics_Chemistry = p_c - ((p_sum * c_sum) / N)

  # Calculate SSCP for mathematics and chemistry
  SSCPMathematics_Chemistry = m_c - ((m_sum * c_sum) / N)

  # Calculate the correlation coefficient
  r1 = SSCPMathematics_Physics / sqrt(SSMathematics * SSPhysics)
  r2 = SSCPPhysics_Chemistry / sqrt(SSPhysics * SSChemistry)
  r3 = SSCPMathematics_Chemistry / sqrt(SSMathematics * SSChemistry)

  # print round(r1,2), '\n', round(r2,2), '\n', round(r3,2)
  stdout.write(str(round(r1,2)) + '\n' + str(round(r2,2)) + '\n' + str(round(r3,2)) + '\n')

  output.write(str(round(r1,2)) + '\n' + str(round(r2,2)) + '\n' + str(round(r3,2)))
