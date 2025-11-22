#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int op = 0;  
        // This variable counts how many numbers need to be changed.

        for (int num : nums) {
            // If a number is NOT divisible by 3,
            // then we need to perform 1 operation on it
            // (because we can convert it to something divisible by 3
            // using exactly 1 operation).
            if (num % 3 != 0)
                op++;
        }

        // Total operations needed
        return op;
    }
};