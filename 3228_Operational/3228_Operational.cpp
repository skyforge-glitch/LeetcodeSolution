#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxOperations(string s) {
        long long ans = 0;    // To store the total operations
        long long ones = 0;   // To count consecutive '1's
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;  // Increment ones when we see '1'
            } else {  // s[i] == '0'
                // If this '0' is followed by '1' or is the last character
                if (i + 1 == n || s[i + 1] == '1') {
                    ans += ones;  // Every previous '1' can form an operation
                }
            }
        }

        return ans;  // Maximum operations
    }
};
