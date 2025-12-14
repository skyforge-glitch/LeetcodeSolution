#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;                 // monotonic decreasing stack (stores values)
        unordered_map<int,int> mp;     // maps each value to its next greater element

        // Step 1: Build Next Greater Element mapping for nums2
        for (int num : nums2) {

            // While current number is greater than the stack top,
            // we found the next greater element for st.top()
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;    // next greater found
                st.pop();              // remove it after processing
            }

            // Push current number to stack (potential candidate)
            st.push(num);
        }

        // Step 2: For remaining stack values, no next greater element exists
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Step 3: Build result for nums1 using the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);    // lookup next greater from map
        }

        return ans;
    }
};