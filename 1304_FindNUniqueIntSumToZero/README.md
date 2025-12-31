# Find N Unique Integers Sum up to Zero (LeetCode 1304)

## 📌 Problem Statement
Given an integer `n`, return **any array containing `n` unique integers** such that their **sum equals 0**.

---

## 🧠 Intuition
- Numbers in the form of `(-x, +x)` cancel each other and contribute `0` to the sum.
- If `n` is **odd**, we include `0` once.
- If `n` is **even**, we only use pairs.
- This guarantees:
  - Sum equals `0`
  - All elements are **unique**
  - Array size is exactly `n`

---

## 🧮 Approach
1. Create an empty result array.
2. If `n` is odd, insert `0`.
3. Add pairs of numbers `(-i, +i)` starting from `i = 1`.
4. Stop once the array size reaches `n`.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        if (n % 2 != 0)
            ans.push_back(0);

        for (int i = 1; ans.size() < n; i++) {
            ans.push_back(-i);
            ans.push_back(i);
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 🧪 Examples

### Example 1
**Input**
```
n = 5
```
**Output**
```
[-2, -1, 0, 1, 2]
```

### Example 2
**Input**
```
n = 4
```
**Output**
```
[-2, -1, 1, 2]
```

---

## 🏁 Summary
- Uses mathematical symmetry
- No extra data structures
- Clean and interview-friendly solution

Happy Coding! 🚀
