#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        // Create a hash set from nums for O(1) average lookup time
        unordered_set<int> mp(nums.begin(), nums.end());

        // Keep doubling original as long as it exists in the hash set
        while (mp.count(original)) {
            original *= 2;   // multiply original by 2
        }
        
        // Once original no longer appears in the set, return it
        return original;
    }
};