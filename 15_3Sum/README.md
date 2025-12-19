# LeetCode 15 — 3Sum

## Problem Overview
Given an integer array `nums`, return **all unique triplets** `[nums[i], nums[j], nums[k]]` such that:
- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set **must not contain duplicate triplets**.

---

## Approach (Two Pointers)

1. **Sort the array** to enable efficient duplicate handling and two-pointer traversal.
2. **Fix one element** (`nums[i]`) and reduce the problem to finding two numbers whose sum equals `-nums[i]`.
3. Use **two pointers**:
   - `low` starting just after `i`
   - `high` starting at the end of the array
4. Adjust pointers based on the comparison between the current sum and the target.
5. **Skip duplicate values** for:
   - The fixed index `i`
   - Both `low` and `high` pointers after finding a valid triplet

This guarantees:
- Optimal time complexity
- Only unique triplets in the result

---

## Implementation (C++)

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int low = i + 1, high = n - 1;

            while (low < high) {
                int sum = nums[low] + nums[high];

                if (sum > target) high--;
                else if (sum < target) low++;
                else {
                    res.push_back({nums[i], nums[low], nums[high]});

                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                }
            }
        }
        return res;
    }
};
```

---

## Complexity Analysis

| Type | Complexity |
|----|----|
| Time Complexity | **O(n²)** |
| Space Complexity | **O(1)** (excluding output) |

---

## Key Notes
- Sorting is essential for duplicate handling
- Two-pointer technique avoids unnecessary nested loops
- Duplicate skipping ensures compliance with problem constraints

---

## Tags
`Array` · `Two Pointers` · `Sorting` · `Hashing Alternative`

---

## LeetCode Link
https://leetcode.com/problems/3sum/

---

⭐ *Efficient, clean, and interview-ready implementation using the Two Pointers technique.*