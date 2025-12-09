# Largest Perimeter Triangle — LeetCode 976

This repository contains a clean C++ solution (with comments) for the problem **Largest Perimeter Triangle**.

## 🔍 Problem Summary
Given an array `nums` of positive integers representing side lengths, find the **maximum perimeter** of a triangle that can be formed using any **three** lengths.  
If no valid triangle can be formed, return `0`.

A valid triangle must satisfy the condition:
```
a + b > c
```
(where `c` is the largest side)

---

## 🧠 Approach
1. **Sort** the array.
2. Traverse from the **largest side downward**.
3. For each triplet `(a, b, c)`, check the triangle inequality.
4. Return the first valid perimeter found (largest possible by construction).

---

## ✅ C++ Code (with comments)
```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        // Sort the side lengths so we can check the largest sides first
        sort(nums.begin(), nums.end());

        // Traverse from the end: try to form a triangle with the largest sides
        for (int i = nums.size() - 1; i >= 2; i--) {

            // Take three consecutive sides (a ≤ b ≤ c)
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];

            // Triangle condition: sum of two smaller sides must be > largest side
            if (a + b > c)
                return a + b + c;   // This is the maximum possible perimeter
        }

        // No valid triangle can be formed
        return 0;
    }
};
```

---

## 📦 File Info
- **Filename:** `readme.md`
- **Downloadable:** Yes

---

Enjoy coding 🚀

---