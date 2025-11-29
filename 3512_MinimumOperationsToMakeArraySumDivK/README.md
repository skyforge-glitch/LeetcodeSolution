# 📘 LeetCode 3512 — Minimum Operations to Make Array Sum Divisible by K

This repository contains a clean C++ solution with comments for **LeetCode 3512**.

---

## 🧩 Problem Summary
You are given:
- an integer array `nums`
- an integer `k`

In **one operation**, you may **decrease any element by 1**.

Your goal is to find the **minimum number of operations** required so that:

```
sum(nums) % k == 0
```

---

## 💡 Intuition
Let:

```
S = sum(nums)
r = S % k
```

Every operation reduces the total sum by exactly **1**.

So to make the sum divisible by `k`, we need to remove exactly `r`.

Thus:

```
Minimum operations = S % k
```

If `S % k == 0`, then no operations are required.

---

## ✅ Commented C++ Solution

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        // calculate total sum of the array
        for (int x : nums) 
            sum += x;

        // remainder tells how much we need to reduce
        // each operation reduces the sum by exactly 1
        return sum % k;  
        // if sum % k == 0 -> already divisible -> 0 operations
    }
};
```

---

## ⏱️ Complexity
- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

## 📝 Example

**Input:**  
```
nums = [1,2,3,1], k = 3
```

**Sum = 7 → 7 % 3 = 1**

**Output:**  
```
1
```

---

## 📎 Notes
- You do **not** need to modify elements individually.  
- Only the **total sum** matters.  

---