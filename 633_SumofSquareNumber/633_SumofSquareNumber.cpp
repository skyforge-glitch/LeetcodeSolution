#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        // Use two-pointer approach
        // low starts from 0, high starts from sqrt(c) because
        // the maximum possible square <= c is sqrt(c)^2
        long long low = 0, high = sqrt(c);

        // Continue until pointers cross
        while (low <= high) {

            // Calculate sum of squares of current pointers
            long long num = (low * low) + (high * high);

            // If sum matches c, we found a valid pair
            if (num == c)
                return true;

            // If sum is smaller, increase low to increase the total
            else if (num < c)
                low++;

            // If sum is larger, decrease high to reduce the total
            else
                high--;
        }

        // No such pair found
        return false;
    }
};
