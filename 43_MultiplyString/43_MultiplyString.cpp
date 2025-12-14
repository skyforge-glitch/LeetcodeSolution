#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        // Edge case: if either number is "0", product is "0"
        if (num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size();   // length of first number
        int len2 = num2.size();   // length of second number
        
        // Result can have at most len1 + len2 digits
        vector<int> result(len1 + len2, 0);

        // Perform digit-by-digit multiplication (school method)
        // Traverse both numbers from right to left
        for (int i = len1 - 1; i >= 0; i--) {
            int k1 = num1[i] - '0';   // current digit of num1

            for (int j = len2 - 1; j >= 0; j--) {
                int k2 = num2[j] - '0';   // current digit of num2

                // Multiply digits and add existing value at position
                int prod = k1 * k2 + result[i + j + 1];

                // Store the unit digit at current position
                result[i + j + 1] = prod % 10;

                // Carry is added to the previous position
                result[i + j] += prod / 10;
            }
        }

        // Convert result array to string, skipping leading zeros
        string ans = "";
        for (int num : result) {
            // Skip leading zeros, but keep zeros after first non-zero digit
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }

        // Handle case where result is all zeros
        return ans.empty() ? "0" : ans;
    }
};