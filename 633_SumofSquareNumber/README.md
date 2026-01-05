# LeetCode 633 — Sum of Square Numbers

## 📌 Problem Statement
Given a non-negative integer `c`, determine whether there exist two integers `a` and `b` such that:

```
a² + b² = c
```

Return `true` if such integers exist, otherwise return `false`.

---

## 💡 Approach: Two Pointer Technique

Instead of checking all possible pairs (which would be inefficient), we use a **two-pointer approach**:

- Start one pointer `low` at `0`
- Start another pointer `high` at `sqrt(c)`
- Compare `low² + high²` with `c`
  - If equal → return `true`
  - If smaller → increase `low`
  - If larger → decrease `high`
- Continue until `low > high`

This approach works efficiently because squares grow monotonically.

---

## 🧠 Algorithm
1. Initialize `low = 0`, `high = floor(sqrt(c))`
2. While `low <= high`:
   - Compute `sum = low² + high²`
   - If `sum == c`, return `true`
   - If `sum < c`, increment `low`
   - Else decrement `high`
3. Return `false`

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0, high = sqrt(c);

        while (low <= high) {
            long long num = (low * low) + (high * high);

            if (num == c)
                return true;
            else if (num < c)
                low++;
            else
                high--;
        }
        return false;
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(√c)`
- **Space Complexity:** `O(1)`

---

## 🔍 Example

**Input:**  
```
c = 5
```

**Explanation:**  
```
1² + 2² = 1 + 4 = 5
```

**Output:**  
```
true
```

---

## 🚀 Notes
- This solution avoids overflow by using `long long`
- Much faster than brute-force `O(c)` approach
- Commonly asked in interviews due to mathematical + pointer logic

---

### ✨ Happy Coding!
