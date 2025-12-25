#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;      // Left pointer of the sliding window
        int cntZero = 0;   // Number of zeros in the current window
        int maxLen = 0;    // Maximum length of valid window found so far

        // Right pointer moves from left to right
        for (int i = 0; i < n; i++) {

            // Include current element in the window
            // Count zeros because they are the elements we can flip
            if (nums[i] == 0)
                cntZero++;

            // If zeros exceed k, shrink window from the left
            while (cntZero > k) {
                // If the element leaving the window is zero,
                // reduce the zero count
                if (nums[left] == 0)
                    cntZero--;
                left++;
            }

            // At this point, window contains at most k zeros
            // Update maximum window length
            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};