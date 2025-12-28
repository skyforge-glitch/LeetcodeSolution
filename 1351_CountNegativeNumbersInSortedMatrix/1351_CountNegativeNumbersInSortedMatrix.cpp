#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Number of rows (m) and columns (n)
        int m = grid.size(), n = grid[0].size();

        // Start from the top-right corner of the matrix
        int row = 0, col = n - 1;

        // Variable to store the total count of negative numbers
        int count = 0;

        // Continue while we are inside the matrix boundaries
        while (row < m && col >= 0) {

            // If the current element is negative
            if (grid[row][col] < 0) {

                // Since columns are sorted in non-increasing order,
                // all elements below grid[row][col] in this column
                // (from row to m-1) are also negative.
                // So we can directly add (m - row) negatives at once.
                count += (m - row);

                // Move left to the previous column
                // because we've already counted all negatives in this column
                col--;

            } else {
                // If the current element is non-negative,
                // then all elements to the left in this row are also non-negative
                // (because the row is sorted).
                // So we move down to the next row.
                row++;
            }
        }

        // Return the total count of negative numbers
        return count;
    }
};