#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();      // Length of the input string
        int i = 0;             // Index pointer to traverse the string
        int result = 0;        // Stores the converted integer value
        int sign = 1;          // Sign of the number (+1 for positive, -1 for negative)

        // 1️⃣ Skip all leading whitespace characters
        // According to the problem, leading spaces should be ignored
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2️⃣ Check for an optional sign ('+' or '-')
        // Only ONE sign is allowed; multiple signs like "+-12" are invalid
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // 3️⃣ Convert consecutive digit characters into an integer
        // Stop parsing as soon as a non-digit character is encountered
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';  // Convert character to integer digit

            // 4️⃣ Check for overflow BEFORE updating the result
            // If result > INT_MAX / 10 → multiplying by 10 will overflow
            // If result == INT_MAX / 10 → adding digit may overflow
            if (result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                // Clamp the value to INT_MAX or INT_MIN depending on the sign
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            // Safe to update result
            result = result * 10 + digit;
            i++;
        }

        // 5️⃣ Apply the sign and return the final integer value
        return result * sign;
    }
};