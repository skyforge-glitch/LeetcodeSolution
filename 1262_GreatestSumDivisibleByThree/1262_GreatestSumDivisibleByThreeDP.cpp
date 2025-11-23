#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[r] stores the maximum sum we can get with remainder r modulo 3
        vector<int> dp(3, 0); // initially all 0

        for (int x : nums) {
            vector<int> temp(dp); // make a copy of current dp to update new sums

            // Try adding x to each of the current dp sums
            for (int r = 0; r < 3; r++) {
                int newSum = dp[r] + x;      // new sum including current number
                int newR = newSum % 3;       // remainder modulo 3
                temp[newR] = max(temp[newR], newSum); // update the best sum for this remainder
            }

            dp = temp; // update dp with the new sums
        }

        return dp[0]; // maximum sum divisible by 3
    }
};