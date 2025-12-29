#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int> freq;

        for (int i = 0; i < n; i++){
            freq[matches[i][0]] += 0;
            freq[matches[i][1]] += 1;
        }

        vector<int> zeroLost, oneLost;

        for (auto &p : freq){
            if (p.second == 0) zeroLost.push_back(p.first);
            else if (p.second == 1) oneLost.push_back(p.first);
        }

        sort(zeroLost.begin(),zeroLost.end());
        sort(oneLost.begin(),oneLost.end());

        return {zeroLost,oneLost};
    }
};