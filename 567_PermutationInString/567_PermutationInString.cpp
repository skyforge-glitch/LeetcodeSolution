#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Length of s1 (pattern string)
        int n = s1.size();

        // Length of s2 (search string)
        int m = s2.size();

        // Frequency map for characters of s1
        // Example: s1 = "ab" → {a:1, b:1}
        unordered_map<char,int> freqS1;
        for (char c : s1)
            freqS1[c]++;

        // Frequency map for current sliding window in s2
        unordered_map<char,int> freqS2;

        // Left pointer of the sliding window
        int left = 0;

        // Right pointer moves using index 'i'
        for (int i = 0; i < m; i++) {

            // Include current character in the window
            freqS2[s2[i]]++;

            // If window size exceeds size of s1,
            // shrink the window from the left
            if (i - left + 1 > n) {

                // Remove the leftmost character
                freqS2[s2[left]]--;

                // If frequency becomes 0, erase it
                // This is IMPORTANT because:
                // {a:0} != {} in unordered_map comparison
                if (freqS2[s2[left]] == 0)
                    freqS2.erase(s2[left]);

                // Move left pointer forward
                left++;
            }

            // If both frequency maps are equal,
            // we found a permutation of s1 in s2
            if (freqS1 == freqS2)
                return true;
        }

        // No permutation found
        return false;
    }
};