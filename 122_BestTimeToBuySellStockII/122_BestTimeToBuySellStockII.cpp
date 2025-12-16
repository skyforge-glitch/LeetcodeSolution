#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();   // Total number of days
        int profit = 0;          // Variable to store total profit

        // Traverse prices from day 1 to last day
        for (int i = 1; i < n; i++){
            // If today's price is higher than yesterday's,
            // we can make a profit by buying yesterday and selling today
            if (prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1]; // Add positive difference
            }
        }
        
        // Return the accumulated maximum profit
        return profit;
    }
};