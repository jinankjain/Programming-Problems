Author: Muhammad Hussein Nasrollahpour

Date: 2014

Problem Statement: A single-elimination tournament (also called an Olympic system tournament, a knockout, single penetration, or sudden death tournament) is a type of elimination tournament where the loser of each game is immediately eliminated from winning the championship or first prize in the event. (Based on Wikipedia, the free encyclopedia)
You are given the results of all games of a single-elimination tournament. There are N = 2K players participating. The tournament consists of K rounds. In each round, the remaining participants are arranged into pairs which play with one another. Find the name of the winning team.
Input format

The first line of input contains one integer N, the number of players (2
≤
 N
≤
 217, N = 2K for some integer K). Each of the next (N - 1) lines contains the result of one game in the form team1 team2, meaning that team team1 won the game against team2. In the description of each game, names are separated by a single space.
All team names are non-empty strings not longer than 10 characters each, containing only lowercase English letters. It is guaranteed that input data describes a correct single-elimination tournament. The games may be given in any order.
Output format

Print the name of the winning team.

Sample:

    Input	 Output

    8       a
    a b
    c d
    e f
    h g
    a c
    e h
    a e
