# LeetCode 496 --- Next Greater Element I

## 🧩 Problem Summary

You are given two integer arrays: - **nums1** (a subset of nums2) -
**nums2** (contains unique values)

For each element in nums1, return its **Next Greater Element (NGE)** in
nums2.\
The NGE of x is the *first element to the right of x in nums2* that is
**greater** than x.\
If no such element exists, return **-1**.

------------------------------------------------------------------------

## 🚀 Approach: Monotonic Stack + Hash Map

### 💡 Why This Works

-   We scan `nums2` once while maintaining a **monotonic decreasing
    stack**.
-   Whenever a number is greater than the stack top → it becomes the
    **next greater element** for that number.
-   We store this mapping in an **unordered_map** for O(1) lookup.
-   Finally, for each number in `nums1`, we directly return its result.

This provides **O(n)** time complexity.

------------------------------------------------------------------------

## ✅ C++ Code Implementation

``` cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;                 // decreasing stack storing values
        unordered_map<int,int> mp;     // maps each value to its next greater

        // Build NGE for nums2
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Remaining stack items have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Build result for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};
```

------------------------------------------------------------------------

## 📊 Time & Space Complexity

  Complexity   Value
  ------------ -----------------------------------------------
  **Time**     O(n) --- each element is pushed & popped once
  **Space**    O(n) --- stack + hash map

------------------------------------------------------------------------

## 🔑 Key Insights

-   Monotonic stacks efficiently solve NGE-type problems.
-   Hash map provides instant lookup for elements in nums1.
-   nums2 is processed once; nums1 queries are O(1).

------------------------------------------------------------------------

## 📝 Additional Notes

This problem is foundational for: - **LC 503** (Next Greater Element
II) - **LC 739** (Daily Temperatures) - **LC 84** (Largest Rectangle in
Histogram) - **Monotonic stack mastery**

A great building block for competitive programming and interviews!
------------------------------------------------------------------------