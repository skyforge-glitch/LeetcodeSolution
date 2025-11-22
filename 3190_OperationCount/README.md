# LeetCode 3190 — Find Minimum Operations to Make All Elements Divisible by 3

## 📝 Problem Summary

You are given an integer array `nums`.  
In **one operation**, you may change **any** element into **any** number you want.

Your goal is to make **every** element divisible by `3` using the **minimum number of operations**.

### Example
**Input:**  
`nums = [1, 2, 3, 4]`

**Output:**  
`3`

**Explanation:**  
Only `3` is divisible by 3.  
All other numbers require exactly **1 operation** each.

---

## 🎯 Key Insight

An element is valid if: num % 3 == 0


If a number is **not** divisible by 3 (`% 3` is 1 or 2),  
we can convert it into a divisible number in **exactly 1 operation**.

Therefore:

👉 **The minimum operations = count of numbers NOT divisible by 3**

---

## ✔️ Approach

1. Iterate through the array.
2. Check if each number is divisible by 3.
3. Count how many are not divisible.
4. Return that count.

---

## ✅ Code (C++)

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c = 0;
        for (int x : nums)
            c += x % 3 != 0;  // +1 if not divisible by 3
        return c;
    }
};
```
---

# Example Walkthrough

Given: nums = [3, 5, 8, 9, 14]


Check each:

- **3** → divisible → no op  
- **5** → not divisible → **+1**
- **8** → not divisible → **+1**
- **9** → divisible → no op  
- **14** → not divisible → **+1**

**Total operations = 3**

---

# Why This Is Simple

Since we can transform a number into *any* value in a single operation,  
**every invalid number requires exactly 1 operation — no more, no less.**

So the entire problem reduces to:

> **Count how many numbers are NOT divisible by the given divisor.**

That's all.

## 🧮 Time & Space Complexity


| **Complexity Type** | **Value** | **Explanation** |
|---------------------|-----------|-----------------|
| Time Complexity     | **O(n)**  | Each element is checked exactly once. |
| Space Complexity    | **O(1)**  | Uses only a constant amount of extra space. |

---