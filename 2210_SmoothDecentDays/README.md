# LeetCode 2110 — Number of Smooth Descent Periods of a Stock

## 🧩 Problem Overview

You are given an integer array `prices`, where `prices[i]` represents the stock price on day `i`.

A **smooth descent period** is defined as a contiguous subarray where:
- The length of the subarray is **at least 1**
- For every adjacent pair in the subarray, the difference is exactly `1`
  ```
  prices[j] - prices[j + 1] == 1
  ```

Your task is to **count all such smooth descent periods** in the array.

---

## 🧠 Key Observations

1. **Every single element is a valid descent period**
   - So, the answer is at least `n` (length of the array).

2. **Consecutive decreasing-by-1 elements can be extended**
   - Example:
     ```
     prices = [5, 4, 3]
     ```
     Valid descent periods:
     - `[5]`, `[4]`, `[3]`
     - `[5,4]`, `[4,3]`
     - `[5,4,3]`

3. The problem reduces to counting **how many descent subarrays end at each index**.

---

## 🚀 Optimized Approach (Single Pass)

We iterate once through the array and:
- Maintain a counter that tracks the **current descent streak**
- If the current element continues a descent (`diff == 1`), extend the streak
- Otherwise, reset the streak

At each index:
- Add the current streak length to the answer

---

## 🧮 Algorithm Steps

1. Initialize:
   - `ans = n` (each element alone)
   - `count = 0` (length of current descent chain)

2. Traverse from index `1` to `n - 1`:
   - If `prices[i - 1] - prices[i] == 1`
     - Increment `count`
   - Else
     - Reset `count = 0`
   - Add `count` to `ans`

3. Return `ans`

---

## ✅ Example Walkthrough

### Input
```
prices = [3, 2, 1, 4]
```

### Execution
| Index | Difference | count | ans |
|------|------------|-------|-----|
| init | —          | 0     | 4   |
| 1    | 3 → 2 ✔    | 1     | 5   |
| 2    | 2 → 1 ✔    | 2     | 7   |
| 3    | 1 → 4 ✖    | 0     | 7   |

### Output
```
7
```

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        // Every element itself is a descent period
        long long ans = n;

        // Length of the current descending-by-1 streak
        long long count = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                count++;      // Extend descent
            } else {
                count = 0;    // Reset streak
            }
            ans += count;     // Add new descent periods ending here
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric            | Complexity |
|-------------------|------------|
| Time Complexity   | `O(n)`     |
| Space Complexity  | `O(1)`     |

---

## 🎯 Why This Works

Each descent streak of length `k` contributes:
```
1 + 2 + ... + k = k*(k+1)/2
```
This solution implicitly accumulates this value **incrementally**, avoiding extra space or nested loops.

---

## 📌 Final Notes

- Elegant one-pass greedy solution
- No extra data structures required
- Common pattern for **subarray counting problems**

Happy coding 🚀

---