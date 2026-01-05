#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int minm = INT_MAX;   // Stores the minimum absolute value in the matrix
        int count = 0;        // Counts how many elements are <= 0 (negative or zero)
        long long sum = 0;    // Stores sum of absolute values of all elements

        // Traverse the entire matrix
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                // Count negative or zero elements
                if (matrix[row][col] <= 0)
                    count++;

                // Track the smallest absolute value
                minm = min(minm, abs(matrix[row][col]));

                // Add absolute value to total sum
                sum += abs(matrix[row][col]);
            }
        }

        /*
            If count of negative numbers is odd:
            - One element must remain negative
            - To maximize sum, make the smallest absolute value negative
            - Hence subtract 2 * minm from total sum
        */
        if (count % 2 != 0)
            return sum - (minm * 2);

        // If count is even, all values can be made positive
        return sum;
    }
};