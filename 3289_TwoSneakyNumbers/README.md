# 📘 LeetCode 3289 — The Two Sneaky Numbers of Digitville

This folder contains the C++ solution for **LeetCode 3289 — The Two Sneaky Numbers of Digitville**, solved using an **O(n) time, O(1) space** approach without using a hashmap.

---

## 🧩 Problem Summary

In Digitville, each number appears **at most once**, except **two numbers**, which appear **exactly twice**.  
Given an array `nums`, your task is to return the **two numbers that appear twice**.

---

## 🎯 Approach Overview

Key facts:
- All numbers lie in the range **0 to 100**.
- Only **two values appear twice**.
- All other values appear once.

Because the number range is fixed and tiny, we can use a **frequency array of size 101**.  
This is considered **O(1) space**, NOT a hashmap.

---

## ⏱️ Time & Space Complexity

- **Time Complexity:** O(n)  
  Only a single pass to count and then 101 constant checks.

- **Space Complexity:** O(1)  
  Uses a fixed-size array of 101 elements.

---

## ✅ C++ Solution (with Comments)

```cpp
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // Frequency array for values 0 to 100 (Digitville range)
        vector<int> arr(101, 0);

        // Count occurrences of each number
        for (int x : nums)
            arr[x]++;

        vector<int> ans;

        // Only two numbers appear exactly twice
        for (int i = 0; i < 101; i++) {
            if (arr[i] == 2)
                ans.push_back(i);
        }

        return ans;
    }
};
```

---

## 📝 Why This Method?

- Avoids sorting  
- Avoids hashmap  
- Extremely fast  
- Always under ~200 operations  
- Fully optimal due to fixed number domain (0–100)

---

## 📦 Folder Contents

- `solution.cpp` — C++ implementation  
- `README.md` — explanation (this file)

---

### 🚀 Happy Coding!