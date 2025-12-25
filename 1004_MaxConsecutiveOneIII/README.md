# 🚀 LeetCode 1004 — Max Consecutive Ones III

## 🧩 Problem Description

You are given a binary array `nums` and an integer `k`.

You may flip **at most `k` zeros** to ones.  
Return the **maximum number of consecutive 1s** in the array after performing at most `k` flips.

---

## 🧠 Key Insight

- The array contains only `0` and `1`
- Flipping a `0` to `1` is equivalent to **allowing at most `k` zeros in a window**
- We want the **largest subarray containing at most `k` zeros**

This is a classic **Sliding Window / Two Pointer** problem.

---

## 💡 Approach — Sliding Window

We maintain a window `[left … right]` such that:
- The number of zeros inside the window is `≤ k`
- Expand the window by moving `right`
- Shrink the window from the left when zero count exceeds `k`
- Track the maximum window length

---

## 🔁 Relation to LeetCode 424

This problem uses the **same sliding window concept** as:

- **LeetCode 424 — Longest Repeating Character Replacement**
- Here:
  - `zeros` → characters to be replaced
  - `k` → number of allowed replacements

---

## 🧪 Example

### Input
```
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
```

### Output
```
6
```

### Explanation
Flip two zeros to get:
```
[1,1,1,0,0,1,1,1,1,1,1]
```
Maximum consecutive ones = `6`

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int cntZero = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                cntZero++;

            while (cntZero > k) {
                if (nums[left] == 0)
                    cntZero--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
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

- Each element enters and leaves the sliding window **at most once**
- This ensures linear time performance
- This is the **optimal solution** for this problem

---

✨ Happy Coding!
