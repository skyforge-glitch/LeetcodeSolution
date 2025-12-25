#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // If k <= 1, no positive product can be < k
        // since all nums[i] >= 1
        if (k <= 1)
            return 0;

        int n = nums.size();

        int ans = 0;          // Stores total count of valid subarrays
        int left = 0;         // Left pointer of sliding window
        long long prod = 1;  // Product of elements in current window

        // Right pointer moves from left to right
        for (int i = 0; i < n; i++) {

            // Include current element in the window
            prod *= nums[i];

            // Shrink the window from the left until
            // product becomes < k again
            while (prod >= k && left <= i) {
                prod /= nums[left];
                left++;
            }

            // Number of valid subarrays ending at index i
            // = window size = (i - left + 1)
            ans += (i - left + 1);
        }

        return ans;
    }
};