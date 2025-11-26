#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {

        long long ans = 0;        // will store the maximum full rows we can form
        long long low = 1;        // binary search start
        long long high = n;       // binary search end (max possible rows is n)

        while (low <= high) {

            // avoid overflow: mid = (low + high) / 2 but written safely
            long long mid = low + (high - low) / 2;

            // total coins needed to build 'mid' full rows
            long long sum = mid * (mid + 1) / 2;

            if (sum <= n) {
                // we can form at least 'mid' rows, try forming more
                ans = mid;
                low = mid + 1;
            } 
            else {
                // too many coins required → try fewer rows
                high = mid - 1;
            }
        }

        // ans contains the maximum number of complete rows
        return ans;
    }
};