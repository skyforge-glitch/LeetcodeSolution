#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {

        // Result vector to store numbers whose sum will be zero
        vector<int> ans;

        /*
            If n is odd, include 0.
            This ensures we can still form pairs
            while keeping the total sum equal to zero.
        */
        if (n % 2 != 0)
            ans.push_back(0);

        /*
            Add pairs (-i, +i).
            Each pair contributes 0 to the sum.
            Continue until we have exactly n elements.
        */
        for (int i = 1; ans.size() < n; i++) {
            ans.push_back(-i);
            ans.push_back(i);
        }

        // Return the constructed array
        return ans;
    }
};