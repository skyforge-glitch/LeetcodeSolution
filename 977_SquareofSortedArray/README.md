# 🚀 LeetCode 977 — Squares of a Sorted Array

## 🧩 Problem Description

You are given an integer array `nums` sorted in **non-decreasing order**.

Return an array of the **squares of each number**, also sorted in **non-decreasing order**.

---

## ❌ Naive Approach (Why it fails)

### Idea
1. Square every element
2. Sort the resulting array

### Complexity
- Squaring: `O(n)`
- Sorting: `O(n log n)`

This works, but **is not optimal**.

---

## 🧠 Key Insight

Although the array is sorted:
- Negative numbers become **positive after squaring**
- Large negative values can produce **larger squares** than positive values

👉 The **largest square** will always come from either:
- the **leftmost element** (most negative), or
- the **rightmost element** (largest positive)

This leads to a **Two Pointer approach**.

---

## 💡 Optimal Approach — Two Pointers

### Strategy
- Use two pointers: `left` and `right`
- Compare `abs(nums[left])` and `abs(nums[right])`
- Place the larger square at the **end** of the result array
- Move pointers inward

---

## 🔁 Step-by-Step Logic

1. Initialize result array of size `n`
2. Set:
   - `left = 0`
   - `right = n - 1`
3. Iterate from the **end of result array**
4. Insert the largest square available
5. Continue until pointers cross

---

## 🧪 Example

### Input
```
nums = [-4, -1, 0, 3, 10]
```

### Process
```
Compare |-4| and |10| → 10² = 100
Compare |-4| and |3|  → (-4)² = 16
Compare |-1| and |3|  → 3² = 9
Compare |-1| and |0|  → (-1)² = 1
Remaining → 0² = 0
```

### Output
```
[0, 1, 9, 16, 100]
```

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int left = 0, right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Value |
|------|------|
| Time Complexity | `O(n)` |
| Space Complexity | `O(n)` |

---

## 🏁 Final Notes

- Uses the **sorted property** of the input array
- Avoids unnecessary sorting
- This is the **optimal and recommended solution**

---

✨ Happy Coding!
