#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0; // i -> children, j -> cookies
        int m = g.size(), n = s.size();

        // Try to satisfy children one by one
        while(i < m && j < n){
            if (s[j] >= g[i]) {
                i++; // child content
            }
            j++; // move to next cookie
        }

        return i; // total content children
    }
};
