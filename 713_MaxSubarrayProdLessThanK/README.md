# 🚀 LeetCode 713 — Subarray Product Less Than K

## 🧩 Problem Description

Given an array of positive integers `nums` and an integer `k`, return the number of **contiguous subarrays** where the **product of all the elements in the subarray is strictly less than `k`**.

---

## 🧠 Key Insight

- All numbers are **positive**, so the product increases when we extend the subarray.
- A **brute-force approach** would check all subarrays → `O(n²)` (too slow).
- We can solve this efficiently using a **Sliding Window / Two Pointer technique**.

---

## 💡 Approach — Sliding Window

We maintain a window `[left … right]` such that:
- The product of elements in the window is `< k`
- Expand the window by moving `right`
- Shrink the window from the left when product `≥ k`

For every valid window ending at `right`, the number of valid subarrays is:
```
right - left + 1
```

---

## ❗ Important Edge Case

If `k ≤ 1`, no valid subarray can exist because:
- All elements are ≥ 1
- Any product will be ≥ 1

So we immediately return `0`.

---

## 🧪 Example

### Input
```
nums = [10, 5, 2, 6]
k = 100
```

### Output
```
8
```

### Explanation
Valid subarrays:
```
[10], [5], [2], [6]
[10,5], [5,2], [2,6]
[5,2,6]
```

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0;
        long long prod = 1;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            ans += (right - left + 1);
        }
        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Value |
|------|------|
| Time Complexity | `O(n)` |
| Space Complexity | `O(1)` |

---

## 🏁 Final Notes

- Each element is added and removed from the window **at most once**
- This guarantees linear time performance
- This is the **optimal solution** for this problem

---

✨ Happy Coding!