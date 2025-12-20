#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        // Number of strings (rows)
        int m = strs.size();

        // Length of each string (columns)
        int n = strs[0].size();

        // Counter to store number of columns that are not sorted
        int notSorted = 0;

        // Iterate over each column
        for (int i = 0; i < n; i++) {

            // Check if the current column is sorted lexicographically
            for (int j = 1; j < m; j++) {

                // If any character is smaller than the one above it,
                // the column is not sorted
                if (strs[j][i] < strs[j - 1][i]) {
                    notSorted++;  // This column must be deleted
                    break;        // No need to check further rows
                }
            }
        }

        // Return total number of columns to delete
        return notSorted;
    }
};