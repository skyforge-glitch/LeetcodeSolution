#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size(); // Number of columns (image is square)

        // Traverse each row of the image
        for (auto& row : image) {
            int i = 0, j = n - 1; // Two pointers for horizontal flip

            // Continue until the pointers cross
            while (i <= j) {
                // If both elements are the same, flipping won't change them
                // So we explicitly invert both
                if (row[i] == row[j]) {
                    int newVal = !row[i]; // Invert: 0 -> 1, 1 -> 0
                    row[i] = row[j] = newVal;
                }
                // Move pointers inward
                i++;
                j--;
            }
        }
        return image; // Return the modified image
    }
};