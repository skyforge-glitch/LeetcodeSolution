#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> mp;
        int ans = 0, left = 0;

        for (int i = 0; i < n; i++){
            while (mp.count(s[i]) && mp[s[i]] >= left){
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

// 15 mins 