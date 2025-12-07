#include <bits/stdc++.h>
using namespace std;

Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;                // Counts how many bottles we get via exchange
        int n = numBottles;         // Current bottles (full or empty after drinking)

        // Keep exchanging as long as empty bottles are enough
        while (n / numExchange > 0) {
            ans += n / numExchange;                  // Add number of new full bottles obtained
            n = (n / numExchange) + n % numExchange; // New full bottles + leftover empty bottles
        }

        // Total bottles drunk = original full bottles + exchanged bottles
        return numBottles + ans;
    }
};