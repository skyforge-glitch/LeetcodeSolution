#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {

        // If k is divisible by 2 or 5, no number made of only 1s
        // can ever be divisible by k (because such numbers end in 1)
        if (k % 2 == 0 || k % 5 == 0) return -1;

        // Start with the first repunit: "1"
        // We store only the remainder instead of the actual number
        int rem = 1 % k;

        // Length of the repunit (number of 1s used so far)
        int len = 1;

        // Keep adding 1s until the remainder becomes 0
        // Each step represents: current_number = current_number * 10 + 1
        // But we only track remainder to avoid overflow
        while (rem != 0) {
            
            // Update remainder after appending another '1'
            rem = (rem * 10 + 1) % k;

            // Increase the count of digits
            len++;
        }

        // When remainder becomes 0, we found the answer
        return len;
    }
};