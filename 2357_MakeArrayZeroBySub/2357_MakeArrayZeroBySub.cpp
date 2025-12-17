#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Set to store distinct non-zero values
        unordered_set<int> distinct;

        // Insert only non-zero elements
        for (int x : nums) {
            if (x != 0) {
                distinct.insert(x);
            }
        }

        // Each distinct non-zero value requires one operation
        return distinct.size();
    }
};