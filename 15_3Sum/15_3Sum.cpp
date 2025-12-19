#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end()); // -> [-4,-1,-1,0,1,2]

        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++){ // -4

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = 0 - nums[i]; // +4
            int low = i + 1, high = n - 1; // -1,2

            while(low < high){
                int sum = nums[low] + nums[high];

                if (sum > target) high--;
                else if (sum < target) low++;

                else {
                    res.push_back({nums[i],nums[low],nums[high]});

                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                };
            }
        }
        return res;
    }
};