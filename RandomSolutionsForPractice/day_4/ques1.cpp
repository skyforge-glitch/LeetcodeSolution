#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int i = 0; i < n; i++){
            if (i >= k){
                maxSum = max(maxSum, currSum);
                currSum -= nums[left++];
            }
            currSum += nums[i];
        }
        maxSum = max(maxSum,currSum);
        
        return maxSum/double(k);
    }
};

// 20 mins (never seen)