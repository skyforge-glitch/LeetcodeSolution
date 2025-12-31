#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        // Total number of elements in the 1D array
        int k = original.size();

        // If total elements do not match m * n,
        // it is impossible to construct the 2D array
        if (k != m * n) 
            return {};

        // Initialize the 2D result array with m rows and n columns
        vector<vector<int>> ans(m, vector<int>(n));

        /*
            Fill the 2D array using index mapping:
            - Row index    = i / n
            - Column index = i % n
        */
        for (int i = 0; i < k; i++) {
            ans[i / n][i % n] = original[i];
        }

        // Return the constructed 2D array
        return ans;
    }
};