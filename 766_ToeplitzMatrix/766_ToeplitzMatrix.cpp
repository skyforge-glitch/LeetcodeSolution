#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // Number of rows
        int m = matrix.size();
        // Number of columns
        int n = matrix[0].size();

        // Traverse the matrix excluding the last row and last column
        // because we compare each element with its bottom-right neighbor
        for (int row = 0; row < m - 1; row++) {
            for (int col = 0; col < n - 1; col++) {
                // If current element is not equal to the element
                // diagonally down-right, it's not a Toeplitz matrix
                if (matrix[row][col] != matrix[row + 1][col + 1]) {
                    return false;
                }
            }
        }

        // If all diagonal elements match, it's a Toeplitz matrix
        return true;
    }
};