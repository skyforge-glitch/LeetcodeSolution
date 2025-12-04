#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // Skip all leading 'L' cars.
        // They move left into empty space → can never collide.
        while (i < n && directions[i] == 'L') 
            i++;

        // Skip all trailing 'R' cars.
        // They move right into empty space → can never collide.
        while (j >= 0 && directions[j] == 'R') 
            j--;

        int collisions = 0;

        // Every car between i and j that is not 'S' (i.e., 'L' or 'R')
        // WILL collide and eventually become 'S'.
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') 
                collisions++;
        }

        return collisions;
    }
};