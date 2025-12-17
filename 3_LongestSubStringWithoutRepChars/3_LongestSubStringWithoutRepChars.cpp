#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();   // Length of the input string
        
        // Map to store the last index where each character was seen
        unordered_map<char,int> setIdx;

        int ans = 0;        // Stores the maximum length found so far
        int left = 0;       // Left boundary of the sliding window

        // Iterate over the string using 'i' as the right boundary of the window
        for (int i = 0; i < n; i++){
            
            // If the current character was seen before AND
            // its last occurrence lies inside the current window
            if (setIdx.count(s[i]) && setIdx[s[i]] >= left){
                
                // Move the left boundary just after the previous occurrence
                // to maintain a window with all unique characters
                left = setIdx[s[i]] + 1;
            } 

            // Update the last seen index of the current character
            setIdx[s[i]] = i;

            // Update the maximum window size
            ans = max(ans, i - left + 1);
        }

        // Return the length of the longest substring without repeating characters
        return ans;
    }
};