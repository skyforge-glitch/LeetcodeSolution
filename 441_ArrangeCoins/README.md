# LeetCode 441 — Arrange Coins

## 🧩 Problem Summary
You are given an integer `n` representing the number of coins.  
Your task is to build a staircase where the *k-th* row requires exactly `k` coins.

Example:
```
Row 1 → 1 coin  
Row 2 → 2 coins  
Row 3 → 3 coins  
...
```

The total coins needed for `k` full rows is:
```
k(k + 1) / 2
```

You must return the **maximum number of complete rows** you can build.

---

## 🚀 Binary Search Solution (Efficient)

### 🔍 Intuition
We search for the maximum `k` such that:
```
k(k+1)/2 ≤ n
```

Using binary search gives **O(log n)** time.

---

## ✅ C++ Solution (Binary Search)

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        long long ans = 0;
        long long low = 1, high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = mid * (mid + 1) / 2;

            if (sum <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## 🧠 Complexity
| Operation | Complexity |
|----------|------------|
| Time     | **O(log n)** |
| Space    | **O(1)** |

---

## 📝 Notes
- Although input `n` is `int`, we use `long long` for calculations to prevent overflow.
- Binary search ensures fast performance even for very large `n`.

---

## 📄 Final Answer
The binary search approach is the optimal and most reliable method to solve LeetCode **441 — Arrange Coins**.