#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        // count = number of zeros seen after the last '1'
        // Initialize with k so the first '1' is always valid
        int count = k;

        for (int num : nums) {

            if (num == 0) {
                // If current value is 0, increase zero-count
                count++;
            }
            else { 
                // num == 1

                // If zeros since previous '1' < k → too close → invalid
                if (count < k) 
                    return false;

                // Reset count because we just found a new '1'
                count = 0;
            }
        }

        // If we never found any invalid spacing, return true
        return true;
    }
};