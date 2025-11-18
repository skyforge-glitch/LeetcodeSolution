#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();  // Get the size of the bits array
        int count = 0;        // Initialize a counter to count consecutive 1's before the last bit

        // Traverse the bits array backwards, starting from the second last element
        for(int i = n - 2; i >= 0; i--) {
            if (bits[i] == 1) 
                count++;  // Increment count if we encounter a 1
            else 
                break;    // Stop counting when we encounter a 0
        }

        // If count of consecutive 1's before last bit is even, the last bit is a one-bit character
        // If count is odd, the last bit is part of a two-bit character
        return count % 2 == 0;
    }
};