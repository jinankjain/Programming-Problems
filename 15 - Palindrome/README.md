Author: Muhammad Hussein Nasrollahpour

Date: 2014

Problem Statement:You are given a string of lowercase letters. Your task is to figure out the index of the character on whose removal will make the string a palindrome. There will always be a valid solution.

In case string is already palindrome, then -1 is also a valid answer along with possible indices.

Input Format
The first line contains T i.e. number of test cases.
T lines follow, each line containing a string.

Output Format
Print the position ( 0 index ) of the letter by removing which the string turns into a palindrome. For string, such as

bcbc
we can remove b at index 0 or c at index 3. Both the answers are accepted.

Constraints
1 ≤ T ≤ 20
1 ≤ length of string ≤ 100005
All characters are latin lower case indexed.

Sample:

    Input

    3
    aaab
    baa
    aaa

    Output

    3
    0
    0
