# Repeated Element in an Array (LeetCode 961)

## 🧩 Problem Statement

You are given an integer array `nums` of size `2N`.

- Exactly **one element** in the array is repeated **N times**
- All other elements appear **only once**

Your task is to **return the element that is repeated N times**.

---

## 🧠 Key Observations

- Since one element appears **N times** in an array of size `2N`,  
  the repeated element will inevitably appear **multiple times early**.
- The moment we encounter the **same element twice**, we already know the answer.

---

## ✅ Approach 1: Hash-based (Unordered Set)

### 💡 Idea
Keep track of elements we have already seen.
- If an element appears again, return it immediately.

### 🧑‍💻 Code (C++)

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return x;
            seen.insert(x);
        }
        return -1;
    }
};
```

### ⏱️ Complexity
| Metric | Value |
|-----|-----|
| Time | O(n) |
| Space | O(n) |

---

## 🚀 Approach 2: Constant Space (Optimal)

### 💡 Key Insight
Since the repeated element appears **N times**, it **cannot be far apart everywhere**.

By the **pigeonhole principle**, it must match with one of its nearby elements.

Checking only a **small window ahead (1–3 positions)** is sufficient.

---

### 🧑‍💻 Code (C++)

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1;
    }
};
```

---

### ⏱️ Complexity
| Metric | Value |
|-----|-----|
| Time | O(n) |
| Space | O(1) |

---

## 🆚 Comparison Summary

| Approach | Time | Space |
|------|------|------|
| Hash-based | O(n) | O(n) |
| Constant Space | O(n) | O(1) |

---

## 🎯 Final Verdict

- Use **hash-based approach** for clarity and simplicity
- Use **constant-space approach** for interviews and optimal performance

---

## 🧠 Interview One-liner

> “Since the repeated element appears N times in a 2N array, it must appear close to itself, allowing an O(1) space solution.”
