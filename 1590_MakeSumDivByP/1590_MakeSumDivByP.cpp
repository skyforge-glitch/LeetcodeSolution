#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        // Calculate total sum
        long long total = 0;
        for (int x : nums) total += x;
        
        // We need to remove a subarray whose sum % p = target
        int target = total % p;

        // If total sum already divisible by p → nothing to remove
        if (target == 0) return 0;

        // Map: prefix_sum_mod → latest index
        unordered_map<int, int> mp;
        mp[0] = -1;  // prefix before array starts

        long long prefix = 0;
        int ans = nums.size();  // store minimum subarray length

        for (int i = 0; i < nums.size(); i++) {

            // current prefix modulo p
            prefix = (prefix + nums[i]) % p;

            // We want previous prefix[j] such that:
            // (prefix[i] - prefix[j]) % p == target
            // → prefix[j] == (prefix[i] - target + p) % p
            int want = (prefix - target + p) % p;

            // If such prefix existed, update answer
            if (mp.count(want)) {
                ans = min(ans, i - mp[want]);
            }

            // Store/update this prefix remainder's index
            mp[prefix] = i;
        }

        // If we never found a valid subarray, return -1
        return ans == nums.size() ? -1 : ans;
    }
};