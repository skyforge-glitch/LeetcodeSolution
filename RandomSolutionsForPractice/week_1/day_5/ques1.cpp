#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> freq;

        int maxLen = 0, maxFreq = 0, left = 0;

        for (int i = 0; i < n; i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq,freq[s[i]]);

            if ((i - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};