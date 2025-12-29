# 🔍 Search a 2D Matrix (LeetCode 74)

## 📌 Problem Statement
You are given an `m x n` integer matrix `matrix` with the following properties:

1. Integers in each row are sorted in ascending order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution with **O(log(m × n))** time complexity.

---

## 🧠 Key Insight
The matrix can be treated as a **flattened sorted 1D array** because:
- Rows are sorted
- Each row starts with a value greater than the previous row's last value

So instead of doing binary search twice, we perform **binary search once** over indices `[0 ... m*n-1]` and map indices back to `(row, col)`.

---

## 🔄 Index Mapping
If `n` is the number of columns:
- `row = mid / n`
- `col = mid % n`

This allows us to access the matrix as if it were a 1D array.

---

## 💡 Algorithm
1. Treat the matrix as a virtual 1D array.
2. Perform binary search on indices `0` to `m*n - 1`.
3. Convert the mid index to `(row, col)` using division and modulo.
4. Compare `matrix[row][col]` with `target`.
5. Adjust binary search bounds accordingly.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(log(m × n))`
- **Space Complexity:** `O(1)` (no extra space used)

---

## 🧪 Example

**Input**
```
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 3
```

**Output**
```
true
```

---

## 🚀 Why This Approach is Optimal
- Uses full binary search power
- No unnecessary row or column scans
- Clean index mapping logic
- Interview-friendly and scalable

---

## 🏁 Conclusion
This solution efficiently leverages the sorted nature of the matrix by flattening the problem into a single binary search, achieving optimal performance.

Happy Coding! 🎯
