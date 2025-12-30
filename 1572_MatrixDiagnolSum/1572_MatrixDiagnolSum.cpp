#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        // Size of the square matrix (n x n)
        int n = mat.size();

        // Variable to store the sum of diagonals
        int sum = 0;

        // i → index for primary diagonal (top-left to bottom-right)
        // j → index for secondary diagonal (top-right to bottom-left)
        int i = 0, j = n - 1;

        // Traverse each row of the matrix
        for (int row = 0; row < n; row++) {

            /*
             If i == j:
               → both diagonals point to the same middle element
               → add it only once (important for odd-sized matrices)
             
             Else:
               → add both primary and secondary diagonal elements
            */
            sum += (i == j) 
                   ? mat[row][i] 
                   : mat[row][i] + mat[row][j];

            // Move to the next diagonal positions
            i++;    // move right for primary diagonal
            j--;    // move left for secondary diagonal
        }

        // Return the final diagonal sum
        return sum;
    }
};