#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;

        // mod will store the remainder of the current binary number % 5
        int mod = 0;
        
        for (int num : nums) {

            // Shift previous binary number left by 1 (multiply by 2),
            // then add the current bit (num),
            // and only keep remainder modulo 5.
            //
            // This ensures we don't store the huge actual number,
            // but we ALWAYS maintain the correct remainder.
            mod = (mod * 2 + num) % 5;

            // If remainder is 0, the binary number formed so far is divisible by 5
            ans.push_back(mod == 0);
        }

        return ans;  // Return the boolean results for all prefixes
    }
};