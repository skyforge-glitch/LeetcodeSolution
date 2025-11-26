#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int m = l.size();                 // number of queries
        vector<bool> ans(m);              // result for each query

        for (int i = 0; i < m; i++) {

            // Extract the subarray nums[l[i] ... r[i]] (r[i] is inclusive)
            vector<int> subArr(nums.begin() + l[i], nums.begin() + r[i] + 1);

            // Sort the subarray so we can check if consecutive differences match
            sort(subArr.begin(), subArr.end());

            int len = subArr.size();      // size of the current subarray

            // For an arithmetic sequence, the difference between every adjacent element must match
            int diff = subArr[1] - subArr[0];

            bool issue = false;           // flag to detect if AP property breaks

            // Check if every pair has the same difference
            for (int j = 2; j < len; j++) {

                // If any difference doesn't match → not arithmetic
                if (subArr[j] - subArr[j - 1] != diff) {
                    issue = true;
                    break;
                }
            }

            // If issue = true → not arithmetic; else arithmetic
            ans[i] = !issue;
        }

        return ans;                       // return results for all queries
    }
};