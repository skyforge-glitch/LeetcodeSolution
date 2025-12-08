#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        // Precompute squares from 0^2 to 250^2
        // squares[i] = i*i
        vector<int> squares(251);
        for (int i = 0; i < 251; i++) 
            squares[i] = i * i;

        // Loop over a and b (here named i and j)
        // i starts from 2 so that smallest useful value is 2
        // j starts from i+1 to avoid duplicates like (3,4) and (4,3)
        for (int i = 2; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                // Compute c = sqrt(a^2 + b^2)
                double z = sqrt(squares[i] + squares[j]);

                // Check TWO things:
                // 1) z == int(z)   → z is an integer (perfect square)
                // 2) z <= n        → c must not exceed n
                if (z == int(z) && z <= n) 
                    ans += 2;  
                    // +2 counts (i, j, c) AND (j, i, c)
            }
        }

        return ans;
    }
};