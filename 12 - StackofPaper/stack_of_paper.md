Author: Muhammad Hussein Nasrollahpour

Date: 2014

Problem Statement:Yury likes to collect problem statements. He keeps statements of all programming contests in which he participated. Recently, he noticed that his collection became too big, so it is hard to find a particular problem in it. So Yury decided to order problem statements on his rectangular desktop.
The problem statements are printed on rectangular sheets of paper. The following rules must be satisfied:
the sides of each sheet of paper must be parallel to the sides of the desktop;
the centers of all sheets coincide;
on each sheet, there exists a point which is not covered by any sheet from the above.
Help Yury and write a program which will find an ordering of sheets with statements satisfying all the rules mentioned above, or find out that such an ordering is impossible.
Input format

The first line of input contains an integer N (1
≤
 N
≤
 105), the number of sheets of paper with problem statements Yury has.
Each of the next N lines contains two space-separated integers wi and hi (1 ≤wi, hi ≤109): width and height of i-th sheet with a problem statement.
Output format

In case the required ordering is possible, print N lines, each containing two integers: width and height of sheets in the stack, listed from bottom to top. Note that sheets can be rotated 90 degrees: in this case, the given width and height will be swapped. Each sheet from the input must appear in the list exactly once. If there is more than one possible solution, print any of them.
In case the required ordering is impossible, print the word “Chaos” (quotes for clarity only).

Sample:

    Input

    4
    3 4
    4 5
    10 1
    3 7

    Output

    10 1
    7 3
    5 4
    4 3
