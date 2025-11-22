#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        // Two-pointer approach:
        // i  -> start of the array
        // j  -> end of the array
        int i = 0, j = height.size() - 1;

        // Stores the maximum water area found so far
        int water = 0;

        // Move both pointers toward each other
        while (i < j) {

            // Current container area:
            // width = (j - i)
            // height = min(height[i], height[j])
            water = max(water, min(height[i], height[j]) * (j - i));

            // Move the pointer with the **shorter height**
            // because only that can potentially increase the area.
            if (height[i] < height[j])
                i++;    // left side is limiting, move it inward
            else
                j--;    // right side is limiting, move it inward
        }

        // Maximum area found
        return water;
    }
};