#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int m = 2*nums.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int j = i % (m/2);
            ans[i] = nums[j];
        }
        return ans;
    }
};