//
//  twotwo.cpp
//  TwoTwo
//
//  Created by Muhammad Hussein Nasrollahpour on 6/6/14
//  Copyright (c) 2014 Chocolate. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define SIZE 1000001

template <typename T> string numberToString(T number)
{
    ostringstream ss;
    ss << number;
    return ss.str();
}

template <typename T> T stringToNumber(const string &st)
{
    istringstream ss(st);
    T result;
    return ss >> result ? result : 0;
}

inline bool isPowerOfTwo(long long int number)
{
    return (number && !(number & (number - 1)));

    /*if (0 == number) return false;

    while (1 != number) {
        if (0 != number % 2) return false;

        number = number / 2;
    }

    return true;*/
}

inline long strength(const char *ary, long i, long j)
{
    long long value = 0;

    stringstream ss1;
    string st1;
    ss1 << ary[i];
    ss1 >> st1;
    int num = stringToNumber<int>(st1);

    if (0 == num) return 0;
    else
        for (; i <= j; i++) {
            stringstream ss2;
            string st2;
            ss2 << ary[i];
            ss2 >> st2;

            value = value * 10 + stringToNumber<int>(st2);
        }

    return value;
}

int main(int argc, const char *argv[])
{
    char T[101];
    char *c_t = fgets(T, 101, stdin);

    string s_t = T;
    long t_i = stringToNumber<long>(s_t);

    char N[SIZE];

    while (fgets(N, SIZE, stdin)) {
        long numOfStrengths = 0;

        string st = N;

        long stLen = st.length();


        for (long i = 0; i < stLen ; i++)
            for (long j = i; j < stLen; j++)
                if (isPowerOfTwo(strength(N, i, j))) numOfStrengths++;

        cout << numOfStrengths << endl;

        if (t_i <= 1) break;

        t_i--;
    }


    return 0;
}
