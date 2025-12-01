#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        // Frequency array for values 0 to 100 (Digitville range)
        vector<int> arr(101, 0);

        // Count occurrences of each number
        for (int x : nums)
            arr[x]++;

        vector<int> ans;

        // Only two numbers appear exactly twice
        for (int i = 0; i < 101; i++) {
            if (arr[i] == 2)
                ans.push_back(i);
        }

        return ans;
    }
};