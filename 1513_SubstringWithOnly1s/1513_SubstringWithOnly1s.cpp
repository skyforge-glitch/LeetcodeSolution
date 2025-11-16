#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        long long mod = 1e9 + 7;

        // ans will store the total number of valid substrings
        long long ans = 0;

        // count keeps track of consecutive '1's in the current streak
        long long count = 0;

        // Traverse the string
        for (char c : s) {

            // If character is '1', increase streak count
            if (c == '1') {
                count++;

                // For every new '1' added to the streak, 
                // the number of new substrings increases by count
                // Example: "111" -> (1) + (2) + (3)
                ans += count;
            } 
            // If character is '0', reset the streak
            else {
                count = 0;
            }
        }

        // Return answer modulo 1e9+7
        return ans % mod;
    }
};