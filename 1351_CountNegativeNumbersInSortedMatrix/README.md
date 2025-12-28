# LeetCode 1351 — Count Negative Numbers in a Sorted Matrix

## 📌 Problem Overview

You are given a `m x n` matrix `grid` where:

- Each **row** is sorted in **non-increasing order**
- Each **column** is sorted in **non-increasing order**

Your task is to **count the number of negative numbers** present in the matrix.

---

## 🧠 Key Observations

- Because rows are sorted, once a negative number appears in a row, **all elements to its right are also negative**.
- Because columns are sorted, once a negative number appears in a column, **all elements below it are also negative**.
- These properties allow us to optimize beyond brute force.

---

## ✅ Approach 1: Brute Force

### 💡 Idea
Traverse every cell in the matrix and count elements that are `< 0`.

### 🧾 Code (C++)

```cpp
int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] < 0)
                count++;
        }
    }
    return count;
}
```

### 📊 Analysis
- Simple and intuitive
- Does **not** use the sorted property of the matrix

---

## ✅ Approach 2: Binary Search on Each Row

### 💡 Idea
Since each row is sorted:
- Use **binary search** to find the **first negative element** in every row
- All elements to the right of it are also negative

### 🧾 Code (C++)

```cpp
int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;

    for (int row = 0; row < m; row++) {
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (grid[row][mid] < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        count += (n - low); // low points to first negative
    }
    return count;
}
```

### 📊 Analysis
- Uses row-wise sorted property
- Faster than brute force
- Slightly more complex logic

---

## ✅ Approach 3: Two Pointers (Staircase Method) — Optimal

### 💡 Idea
Start from the **top-right corner** of the matrix:
- If current value is negative → all values **below** are negative
- If current value is non-negative → move **down**

Each step removes either a row or a column from consideration.

### 🧾 Code (C++)

```cpp
int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int row = 0, col = n - 1;
    int count = 0;

    while (row < m && col >= 0) {
        if (grid[row][col] < 0) {
            count += (m - row);
            col--;
        } else {
            row++;
        }
    }
    return count;
}
```

### 📊 Analysis
- Uses both **row-wise and column-wise sorted properties**
- Each row and column is visited at most once
- This is the **best possible solution**

---

## ⏱️ Time & Space Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|--------|-----------------|------------------|
| Brute Force | O(m × n) | O(1) |
| Binary Search | O(m log n) | O(1) |
| Staircase (Two Pointers) | **O(m + n)** | **O(1)** |

---

## 🏁 Final Notes

- Start with brute force for correctness
- Optimize using binary search if only rows are sorted
- Use the **staircase method** when both rows and columns are sorted

This problem is a classic example of leveraging **monotonic properties** in 2D matrices.

Happy Coding 🚀
