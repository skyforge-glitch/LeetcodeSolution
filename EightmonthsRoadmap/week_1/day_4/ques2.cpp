#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left = 0, sum = 0;
        int minLen = n + 1;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            while (sum >= target){
                minLen = min(minLen, i - left + 1);
                sum -= nums[left++];
            }
        }
        return minLen == n + 1 ? 0 : minLen;
    }
};

// 30mins (never seen)