# Remove Duplicates from Sorted Array II

## 🧩 Problem Statement

Given a **sorted integer array `nums`**, remove duplicates **in-place** such that **each unique element appears at most twice**.

The relative order of the elements should be preserved.

Return the number of elements after removing the extra duplicates.

> ⚠️ You must do this with **O(1) extra space**.

---

## ✅ Example

### Input
```txt
nums = [0,0,1,1,1,1,2,3,3]
```

### Output
```txt
5
```

### Modified Array (first 5 elements)
```txt
[0,0,1,1,2]
```

---

## 💡 Key Idea

Since the array is **already sorted**:

- Any duplicates will be adjacent.
- Each number is allowed to appear **at most twice**.
- We can compare the current element with the element **two positions before** the insertion index.

If they are different → it’s safe to keep the element.

---

## 🧠 Algorithm (Two Pointer Technique)

1. If array length ≤ 2, return its size directly.
2. Initialize a pointer `idx = 2` (first two elements are always valid).
3. Iterate from index `2` to `n-1`:
   - If `nums[i] != nums[idx - 2]`, copy `nums[i]` to `nums[idx]` and increment `idx`.
4. Return `idx` as the new length.

---

## 🧪 Dry Run

Input:
```txt
nums = [1,1,1,2,2,3]
```

Steps:
```txt
idx = 2
i = 2 → nums[2] == nums[0] → skip
i = 3 → nums[3] != nums[1] → keep → idx = 3
i = 4 → nums[4] != nums[2] → keep → idx = 4
i = 5 → nums[5] != nums[3] → keep → idx = 5
```

Result:
```txt
[1,1,2,2,3]
```

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int idx = 2;  // first two are always allowed

        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[idx - 2]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |

---

## 🎯 Takeaways

- Sorted arrays allow **pattern-based duplicate control**.
- Comparing with `idx - 2` is the key insight.
- Clean, in-place solution with optimal complexity.

---

Happy Coding 🚀