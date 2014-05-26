Author: Muhammad Hussein Nasrollahpour

Date: 2014

Problem Statement: While exploring his new house, Alexey found an infinite flat board with a square grid on it. He decided to use it as a darts board. For that, he selected n sequential rows and m sequential columns and wrote an integer in each of the m ⋅ n selected cells. When Alexey throws a dart and it hits one of the selected cells, his score is equal to the number written in that cell. If the dart hits a cell outside the selected m × n cells, Alexey's score is equal to zero.
After some training, Alexey improved his skills, so now he can almost hit the selected cell. More precisely, if Alexey throws a dart aiming at some cell, the dart with hit that cell with probability 1 / 2. In case he misses the target, the dart hits one of the eight neighboring cells equiprobably.
Now Alexey has only one dart. He wonders which cell he must aim at to maximize his expected score after one throw.
Input format

The first line of input contains two integers n and m (1 ≤ n, m ≤ 500). Each of the next n lines contain m non-negative space-separated integers which are the scores for hitting the respective cells. Each of these scores does not exceed 107.
Output format

Print two integers: the number of row and the number of column of the cell which Alexey should aim at to maximize his expected score. Rows and columns are numbered starting from 1. If several correct answers are possible, print any of them.

Sample:

	Input	Output
	3 3	2 2
	1 1 1
	1 2 1
	1 1 1
