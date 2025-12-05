#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int partitions = 0;
        int sum = 0;

        // Compute total sum of the array
        for (int num : nums) 
            sum += num;

        // If total sum is odd, it's impossible for two parts to have equal parity
        if (sum % 2 == 1) 
            return 0;

        int l = 0;  // prefix sum (left part)

        // Try partitioning between index i and i+1
        for (int i = 0; i < n - 1; i++) {
            l += nums[i];   // update left sum
            sum -= nums[i]; // now sum represents right sum

            // A valid partition requires left_sum and right_sum to have same parity
            if (abs(l - sum) % 2 == 0) 
                partitions++;
        }

        return partitions;
    }
};