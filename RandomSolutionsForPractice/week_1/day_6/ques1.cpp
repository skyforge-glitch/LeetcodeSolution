#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        unordered_map<char,int> freqS1;
        for (char c :  s1) freqS1[c]++;

        unordered_map<char,int> freqS2;
        int left = 0;

        for (int i = 0; i < m; i++){
            freqS2[s2[i]]++;

            if (i - left + 1 > n){
                freqS2[s2[left]]--;
                // if a char leave the map
                // it becomes 'c' : 0
                // but we want it to be not there
                if (freqS2[s2[left]] == 0) freqS2.erase(s2[left]);
                left++;
            }

            if (freqS1 == freqS2) return true;
        }
        return false;;
    }
};