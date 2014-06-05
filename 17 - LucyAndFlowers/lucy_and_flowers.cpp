//
//  lucy_and_flowers.cpp
//  Lucy&Flowers
//
//  Created by Muhammad Hussein Nasrollahpour on 6/5/14
//  Copyright (c) 2014 Chocolate. All rights reserved.
//

#include <iostream>

using namespace std;

long countNumberofBSTs(int numOfFlowers)
{
    // FIXME: Use memoization.

    if (0 == numOfFlowers || 1 == numOfFlowers)
        return 1;
    else {
        long left, right, bsts = 0;

        for (int idx = 1; idx <= numOfFlowers; idx++) {
            left = countNumberofBSTs(idx - 1);
            right = countNumberofBSTs(numOfFlowers - idx);

            bsts += (left * right);
        }

        return bsts;
    }

    return -1;
}

int main(int argc, const char *argv[])
{
    int T = 0;
    cin >> T;

    while (T >= 1) {
        int numOfFlowers = 0;
        cin >> numOfFlowers;

        cout << countNumberofBSTs(numOfFlowers) << endl;

        T--;
    }

    return 1;
}
