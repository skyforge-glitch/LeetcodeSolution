# 3507. Minimum Pair Removal to Sort Array I

![LeetCode](https://img.shields.io/badge/LeetCode-Easy-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Simulation-orange)
![Status](https://img.shields.io/badge/Status-Accepted-success)

## 🧩 Problem Statement

You are given an integer array `nums`.

You can perform the following operation any number of times:

1. Select the **adjacent pair with the minimum sum**
2. If multiple such pairs exist, choose the **leftmost**
3. Replace the pair with **their sum**

Return the **minimum number of operations** needed to make the array **non-decreasing**.

---

## 💡 Approach

- If the array is already non-decreasing, return `0`
- Otherwise, repeatedly:
  - Find the adjacent pair with the minimum sum
  - Merge the pair
  - Count one operation
- Stop when the array becomes non-decreasing

The operation choice is forced, so simulation gives the minimum operations.

---

## 🧑‍💻 C++ Solution

```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (true) {
            bool sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break;

            int minSum = INT_MAX, idx = 0;
            for (int i = 0; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }

        return ops;
    }
};
```

---

## ⏱️ Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)`

---

## ✅ Notes

- Pure simulation problem
- Works within constraints
- Easy to reason and implement

Happy coding 🚀