#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        // Every single element itself forms a valid descent period
        // So initially, the answer is at least n
        long long ans = n;

        // This keeps track of the length of the current
        // consecutive descending-by-1 sequence
        long long count = 0;

        // Start from the second element and compare with the previous one
        for (int i = 1; i < n; i++) {

            // Check if the current price is exactly 1 less than the previous price
            if ((prices[i - 1] - prices[i]) == 1) {
                // Extend the current descent sequence
                count++;
            } else {
                // Break in descent, reset the counter
                count = 0;
            }

            // Add the number of new descent periods ending at index i
            ans += count;
        }

        // Total number of smooth descent periods
        return ans;
    }
};