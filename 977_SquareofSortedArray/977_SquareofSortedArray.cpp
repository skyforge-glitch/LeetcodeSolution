#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        // Result array to store squares in sorted order
        vector<int> res(n);

        // Two pointers:
        // left  -> start of array (most negative value)
        // right -> end of array (largest positive value)
        int left = 0, right = n - 1;

        // Fill the result array from the end to the beginning
        // because the largest square will come from either
        // the leftmost or rightmost element
        for (int i = n - 1; i >= 0; i--) {

            // Compare absolute values to find the larger square
            if (abs(nums[left]) > abs(nums[right])) {
                // Square the left element and place it at current position
                res[i] = nums[left] * nums[left];
                left++;   // Move left pointer inward
            } else {
                // Square the right element and place it at current position
                res[i] = nums[right] * nums[right];
                right--;  // Move right pointer inward
            }
        }

        // Result array is already sorted
        return res;
    }
};