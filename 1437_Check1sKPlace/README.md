# LeetCode 1437 — Check If All 1's Are at Least K Places Away
# 📘 Problem Summary

You are given a binary array nums and an integer k.
Your task is to determine whether every pair of consecutive 1s in the array is separated by at least k zeros.

Formally, for every two indices `i` and `j` where `nums[i] == nums[j] == 1` and `i < j`, we must have:

```j - i - 1 >= k```

# ✅ Approach: Zero Counter Method (Optimal)

We traverse the array while maintaining a counter of zeros since the last encountered 1.

Key ideas:

- Initialize count = k so the first 1 is always allowed.
- When encountering a 0, increase the counter.
- When encountering a 1:
- If count < k, the distance is invalid → return false.
- Otherwise, reset count = 0.

# Complexity:

-  Time: O(n)

- Space: O(1)

This is one of the cleanest and most efficient solutions.

# 🧩 Code Implementation
```class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        // count = number of zeros seen after the last '1'
        // Initialize with k so the first '1' is always valid
        int count = k;

        for (int num : nums) {

            if (num == 0) {
                // If current value is 0, increase zero-count
                count++;
            }
            else { 
                // num == 1

                // If zeros since previous '1' < k → too close → invalid
                if (count < k) 
                    return false;

                // Reset count because we just found a new '1'
                count = 0;
            }
        }

        // No spacing violations found
        return true;
    }
};
```

# 📌 Example
Input:
nums = [1,0,0,0,1], k = 2

Output:
true

# Explanation:

Distance between the two 1s is 3 indexes → 3 - 0 - 1 = 2 zeros → valid.

✔️ Why This Works

The rule requires at least k zeros between two ones.
Instead of tracking indices, we maintain a counter that naturally tracks the spacing as we iterate.

This avoids unnecessary index bookkeeping and gives a very clean O(1)-space solution.