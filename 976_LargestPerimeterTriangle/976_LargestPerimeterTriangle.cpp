#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        // Sort the side lengths so we can check the largest sides first
        sort(nums.begin(), nums.end());

        // Traverse from the end: try to form a triangle with the largest sides
        for (int i = nums.size() - 1; i >= 2; i--) {

            // Take three consecutive sides (a ≤ b ≤ c)
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];

            // Triangle condition: sum of two smaller sides must be > largest side
            if (a + b > c)
                return a + b + c;   // This is the maximum possible perimeter
        }

        // No valid triangle can be formed
        return 0;
    }
};