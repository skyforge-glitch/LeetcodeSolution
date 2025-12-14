# LeetCode 503 --- Next Greater Element II

## 🧩 Problem Summary

You are given a **circular integer array** `nums`.\
For every element in the array, you must find the **Next Greater Element
(NGE)**.

The twist:\
Because the array is *circular*, after reaching the last index, the
search continues from index `0`.

If no greater element exists, return **-1**.

------------------------------------------------------------------------

## 🔥 Example

**Input:**

    nums = [1, 2, 1]

**Output:**

    [2, -1, 2]

Explanation:\
- For the first `1`, the next greater element is `2`\
- For `2`, no greater element exists → `-1`\
- For the last `1`, circular search makes its next greater `2`

------------------------------------------------------------------------

# 🚀 Optimized Approach --- Monotonic Stack (O(n))

## 💡 Key Insight

For circular behavior, simulate the array twice:

    for i in range(0, 2*n):
        j = i % n

Use a **monotonic decreasing stack** storing *indices*.\
When `nums[j]` is greater than `nums[stack.top()]`, we found the next
greater element.

We also store `ans[]` initialized to `-1`, and **only push indices that
still need answers**.

------------------------------------------------------------------------

# ✅ C++ Code (Optimized)

``` cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < n + n; i++) {
            int j = i % n;

            while (!st.empty() && nums[j] > nums[st.top()]) {
                ans[st.top()] = nums[j];
                st.pop();
            }

            if (ans[j] == -1) st.push(j);
        }

        return ans;
    }
};
```

------------------------------------------------------------------------

# 📊 Complexity Analysis

  Metric                 Value
  ---------------------- -------
  **Time Complexity**    O(n)
  **Space Complexity**   O(n)

------------------------------------------------------------------------

# 🔑 Key Concepts

-   Monotonic decreasing stack\
-   Circular traversal with modulo\
-   Efficient NGE computation

------------------------------------------------------------------------

# 🧠 Related Problems

-   496 --- Next Greater Element I\
-   739 --- Daily Temperatures\
-   84 --- Largest Rectangle in Histogram\
-   42 --- Trapping Rain Water

------------------------------------------------------------------------

# 🎯 Conclusion

This problem strengthens your understanding of: - Circular arrays\
- Monotonic stack patterns\
- O(n) array processing

