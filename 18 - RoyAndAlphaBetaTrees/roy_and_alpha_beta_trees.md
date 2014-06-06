Author: Muhammad Hussein Nasrollahpour

Date: 2014

Problem Statement:Roy has taken a liking to the Binary Search Trees(BST). He is interested in knowing the number of ways an array A of N integers can be arranged to form a BST. Thus, he tries a few combinations, and notes down the numbers at the odd levels and the numbers at the even levels.

You’re given two values, alpha and beta. Can you calculate the sum of Liking of all possible BST’s that can be formed from an array of N integers? Liking of each BST is defined as follows

(sum of numbers on even levels * alpha) - (sum of numbers on odd levels * beta)
Note

The root element is at level 0 ( Even )
The elements smaller or equal to the parent element are present in the left subtree, elements greater than or equal to the parent element are present in the right subtree. Explained here
If the answer is no less than 109 + 9, output the answer % 109 + 9.

Update

If the answer is less than 0, keep adding 109 + 9 until the value turns non negative.

Input Format
The first line of input file contains an integer, T, denoting the number of test cases to follow.
Each testcase comprises of 3 lines.
The first line contains N, the number of integers.
The second line contains two space separated integers, alpha and beta.
The third line contains space separated N integers, denoting the ith integer in array A[i].

Output Format
Output T lines. Each line contains the answer to its respective test case.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 150
1 ≤ A[i] ≤ 109
1 ≤ alpha,beta ≤ 109

Sample

    Input

    4
    1
    1 1
    1
    2
    1 1
    1 2
    3
    1 1
    1 2 3
    5
    1 1
    1 2 3 4 5

    Output

    1
    0
    6
    54
