#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0; // total sum of all numbers

        vector<int> mod1; // numbers with remainder 1 when divided by 3
        vector<int> mod2; // numbers with remainder 2 when divided by 3

        // Separate numbers based on their remainder modulo 3
        for (int x : nums){
            total += x;       // accumulate total sum
            if (x % 3 == 1) 
                mod1.push_back(x); 
            else if (x % 3 == 2) 
                mod2.push_back(x);
        }

        // Sort the remainder arrays to easily get smallest numbers
        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        // If total sum is already divisible by 3, return it directly
        if (total % 3 == 0) return total;

        // Initialize removal options with a very large number
        int rm1 = INT_MAX, rm2 = INT_MAX;

        // Case 1: total % 3 == 1
        if (total % 3 == 1){
            // Option 1: Remove the smallest number with remainder 1
            if (mod1.size()) rm1 = mod1[0];
            // Option 2: Remove the sum of two smallest numbers with remainder 2
            if (mod2.size() >= 2) rm2 = mod2[0] + mod2[1];
        } 
        // Case 2: total % 3 == 2
        else {
            // Option 1: Remove the smallest number with remainder 2
            if (mod2.size()) rm2 = mod2[0];
            // Option 2: Remove the sum of two smallest numbers with remainder 1
            if (mod1.size() >= 2) rm1 = mod1[0] + mod1[1];
        }

        // Subtract the minimum removal option to maximize sum divisible by 3
        return total - min(rm1, rm2);
    }
};