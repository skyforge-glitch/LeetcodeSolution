# LeetCode 944 — Delete Columns to Make Sorted

## Problem Overview
You are given an array of strings `strs` where all strings have the same length. A column is considered **sorted** if the characters in that column appear in **non-decreasing lexicographical order** from top to bottom.

The task is to determine the **minimum number of columns that must be deleted** so that all remaining columns are sorted.

---

## Approach

- Treat the input as a **grid of characters**:
  - Rows → strings
  - Columns → character positions
- Traverse the grid **column by column**.
- For each column, compare characters row-wise:
  - If any character is smaller than the one above it, the column is not sorted.
  - Increment the deletion counter and move to the next column.
- Stop checking a column as soon as it is found to be unsorted.

This approach works because each column is **independent** and does not affect others.

---

## Implementation (C++)

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();        // number of strings (rows)
        int n = strs[0].size();     // length of each string (columns)

        int notSorted = 0;          // count of columns to delete

        // Traverse each column
        for (int i = 0; i < n; i++) {
            // Check if column i is sorted
            for (int j = 1; j < m; j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    notSorted++;   // column is not sorted
                    break;         // move to next column
                }
            }
        }
        return notSorted;
    }
};
```

---

## Complexity Analysis

| Type | Complexity |
|---|---|
| Time Complexity | **O(m × n)** |
| Space Complexity | **O(1)** |

Where:
- `m` = number of strings
- `n` = length of each string

This is optimal because every character may need to be inspected in the worst case.

---

## Key Notes
- The solution checks columns independently
- Early termination is used once a column is found unsorted
- No additional data structures are required

---

## Tags
`Array` · `String` · `Simulation`

---

⭐ *Efficient and optimal solution using direct column-wise traversal.*

