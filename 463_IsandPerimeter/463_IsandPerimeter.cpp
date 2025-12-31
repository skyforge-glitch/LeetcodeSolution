#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        // Number of rows in the grid
        int n = grid.size();

        // Number of columns in the grid
        int m = grid[0].size();

        // Variable to store the total perimeter
        int perimeter = 0;

        // Traverse each cell of the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                // Process only land cells
                if (grid[row][col] == 1) {

                    /*
                        For each land cell, check all 4 directions.
                        If the adjacent cell is:
                        - outside the grid OR
                        - water (0)
                        then that side contributes 1 to the perimeter.
                    */

                    // Check upper side
                    if (row - 1 < 0 || grid[row - 1][col] == 0)
                        perimeter++;

                    // Check lower side
                    if (row + 1 >= n || grid[row + 1][col] == 0)
                        perimeter++;

                    // Check left side
                    if (col - 1 < 0 || grid[row][col - 1] == 0)
                        perimeter++;

                    // Check right side
                    if (col + 1 >= m || grid[row][col + 1] == 0)
                        perimeter++;
                }
            }
        }

        // Final calculated perimeter of the island
        return perimeter;
    }
};