# Convert 1D Array Into 2D Array (LeetCode 2022)

## 📌 Problem Statement
You are given a **1D integer array** `original` and two integers `m` and `n`.

Your task is to construct a **2D array of size `m x n`** using all elements of `original` **in row-wise order**.

If it is **not possible** to construct such a 2D array, return an **empty array**.

---

## 🧠 Intuition
- A valid 2D array of size `m x n` must contain exactly `m * n` elements.
- If the size of the original array does not match `m * n`, construction is impossible.
- Otherwise, we can map each 1D index to a 2D position using math.

---

## 🧮 Approach
1. Check if `original.size() == m * n`.
2. Create an empty 2D vector with `m` rows and `n` columns.
3. Traverse the 1D array and place elements row by row using:
   - Row index = `i / n`
   - Column index = `i % n`
4. Return the constructed 2D array.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k = original.size();
        if (k != m * n) return {};

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < k; i++) {
            ans[i / n][i % n] = original[i];
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(m × n)`
- **Space Complexity:** `O(m × n)`

---

## 🧪 Example

**Input**
```
original = [1,2,3,4]
m = 2, n = 2
```

**Output**
```
[[1,2],
 [3,4]]
```

---

## 🏁 Summary
- Uses simple index mapping
- Clean and efficient solution
- Perfect for interviews and competitive programming

Happy Coding! 🚀
