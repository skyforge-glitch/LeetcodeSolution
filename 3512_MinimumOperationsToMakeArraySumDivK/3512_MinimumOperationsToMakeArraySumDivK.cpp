#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        // calculate total sum of the array
        for (int x : nums) 
            sum += x;

        // remainder tells how much we need to reduce
        // because each operation reduces the sum by exactly 1
        return sum % k;  
        // if sum % k == 0 -> already divisible -> 0 operations
    }
};