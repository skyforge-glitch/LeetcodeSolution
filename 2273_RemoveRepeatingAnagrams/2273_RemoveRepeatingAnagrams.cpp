#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;       // stores final list after removing anagrams
        string prev = "";         // stores sorted version of the last accepted word

        for (auto &w : words) {
            string sortedW = w;                    // make a copy of the current word
            sort(sortedW.begin(), sortedW.end());  // sort letters → anagram signature

            // If sorted form is not same as previous,
            // this word is NOT a consecutive anagram → keep it
            if (sortedW != prev) {
                ans.push_back(w);     // keep original word
                prev = sortedW;       // update previous signature
            }
        }

        return ans;
    }
};