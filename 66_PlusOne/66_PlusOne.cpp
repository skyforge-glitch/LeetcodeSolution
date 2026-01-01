#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Start from the last digit (least significant digit)
        int end = digits.size() - 1;

        // Traverse the number from right to left
        while (end >= 0){
            // Case 1: Current digit is not 9
            // We can safely add 1 and finish
            if (digits[end] != 9){
                digits[end]++;
                return digits;   // No carry further, return result
            } 
            else {
                // Case 2: Current digit is 9
                // Adding 1 makes it 0 and generates a carry
                digits[end] = 0;
                end--;           // Move to the next digit on the left
            }
        }

        // If we exit the loop, it means all digits were 9
        // Example: 999 -> 1000
        // Insert 1 at the beginning to handle the extra carry
        digits.insert(digits.begin(), 1);

        return digits;
    }
};