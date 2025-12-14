#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        // Stack to keep indices of elements for which we haven't found the next greater element yet
        stack<int> st;
        
        // Initialize the result array with -1, meaning "no greater element found"
        vector<int> ans(n, -1);

        // Loop twice through the array to simulate the circular nature
        for (int i = 0; i < n + n; i++) {
            // Use modulo to wrap the index around when i >= n
            int j = i % n;

            // Pop from the stack while the current element is greater than the element at the index on top of the stack
            while (!st.empty() && nums[j] > nums[st.top()]) {
                // The current element is the next greater element for the element at st.top()
                ans[st.top()] = nums[j];
                st.pop();
            }

            // If we haven't found a next greater element for index j, push it onto the stack
            if (ans[j] == -1) {
                st.push(j);
            }
        }

        return ans;
    }
};