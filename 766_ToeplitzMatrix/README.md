# Toeplitz Matrix — All Approaches Explained

This document explains **three progressively constrained solutions** to the Toeplitz Matrix problem, including **streaming and partial-row scenarios** often discussed in interviews.

---

## Problem Recap

A matrix is **Toeplitz** if **every diagonal from top-left to bottom-right has the same element**.

Formally:
```
matrix[i][j] == matrix[i+1][j+1]
```

---

## Approach 1: Full Matrix in Memory (Optimal Case)

### Idea
If the entire matrix fits in memory, simply compare each element with its bottom-right diagonal neighbor.

### Algorithm
- Traverse the matrix (excluding last row & column)
- Check `matrix[i][j] == matrix[i+1][j+1]`

### Code (C++)

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

### Complexity
- **Time:** O(m × n)
- **Space:** O(1)

✅ **Best possible solution when memory is not constrained.**

---

## Approach 2: Row-by-Row Streaming

### Constraint
- The matrix is too large to fit entirely in memory
- You can load **one full row at a time**

### Idea
Each element must match the element **diagonally above-left**, which lies in the previous row.

### Algorithm
- Store the previous row
- Compare `current[j]` with `prev[j-1]`

### Code (C++)

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev = matrix[0];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != prev[j - 1]) {
                    return false;
                }
            }
            prev = matrix[i];
        }
        return true;
    }
};
```

### Complexity
- **Time:** O(m × n)
- **Space:** O(n)

✅ **Optimal under row-streaming constraints.**

---

## Approach 3: Partial-Row Streaming (Disk / Chunked Input)

### Constraint
- The matrix is stored on disk or streamed
- You **cannot load a full row**
- Elements arrive in **small chunks**

### Key Insight
Elements on the same diagonal share the same value.

A diagonal can be uniquely identified by:
```
diagonal_id = j - i
```

### Strategy
- Track each diagonal’s first value in a hash map
- For every incoming element:
  - If diagonal is unseen → store value
  - If seen → verify it matches

### Pseudocode

```
create empty map diag_value

for each element (i, j) read sequentially:
    key = j - i

    if key not in diag_value:
        diag_value[key] = matrix[i][j]
    else if diag_value[key] != matrix[i][j]:
        return false

return true
```

### Complexity
- **Time:** O(m × n)
- **Space:** O(min(m, n))

✅ **Optimal and necessary under partial-row streaming constraints.**

---

## Final Comparison

| Scenario | Time | Space |
|--------|------|-------|
| Full matrix in memory | O(mn) | O(1) |
| One row at a time | O(mn) | O(n) |
| Partial row only | O(mn) | O(min(m,n)) |

---

## Interview Notes

- The **first solution is globally optimal**
- Follow-up constraints **force increased space**
- The third approach tests **invariant reasoning**, not real-world RAM limits
- Explaining the idea is usually sufficient; full code is rarely required

---

## Takeaway

As constraints tighten, **space complexity must increase** to preserve correctness.  
Each solution here is **optimal under its respective constraints**.

