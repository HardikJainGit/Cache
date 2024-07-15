#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/powx-n/

class Solution {
public:

    double myPow(double x, int n) {
        if (x == 0) return 0; // Handle the case when x is 0

        double res = 1;
        long long n_copy = n; // Use long long to avoid overflow
        if (n_copy < 0) {
            x = 1 / x; // Handle negative power
            n_copy *= -1;
        }

        while (n_copy > 0) {
        
            // Check if odd if yes then multiply extra x
            if (n_copy & 1)
                res *= x;

            x *= x; // the usual

            // Keep dividing by 2

            n_copy >>= 1;
        }

        return res;
    }

};