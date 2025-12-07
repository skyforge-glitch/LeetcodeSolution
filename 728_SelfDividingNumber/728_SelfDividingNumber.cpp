#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        // Loop through every number in the given range
        for (int i = left; i <= right; i++) {

            int z = i;        // Temporary variable to extract digits
            bool ok = true;   // Flag to check if number is self-dividing

            // Extract digits of the number
            while (z != 0) {
                int d = z % 10;      // Get last digit

                // If digit is 0 or number is not divisible by this digit
                if (d == 0 || i % d != 0) {
                    ok = false;      // Mark number as invalid
                    break;           // No need to check further digits
                }

                z /= 10;             // Remove last digit
            }

            // If all digits could divide the number, add it to answer
            if (ok) ans.push_back(i);
        }

        return ans;   // Return all self-dividing numbers in range
    }
};