# Island Perimeter (LeetCode 463)

## 📌 Problem Statement
You are given a `row x col` grid representing a map where:

- `1` represents **land**
- `0` represents **water**

The grid contains **exactly one island** (or none).  
The island is completely surrounded by water, and there are no lakes inside the island.

Your task is to **return the perimeter of the island**.

---

## 🧠 Intuition
- Each **land cell contributes 4 sides**
- If a side touches **water or the grid boundary**, it adds **1 to the perimeter**
- If a side touches another **land cell**, it does **not** add to the perimeter

We simply check all **4 directions** for every land cell.

---

## 🧮 Approach
1. Traverse the entire grid.
2. For every land cell (`1`):
   - Check **up, down, left, right**
   - If the adjacent cell is out of bounds or water, increment the perimeter.
3. Return the final perimeter.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    if (row - 1 < 0 || grid[row - 1][col] == 0) perimeter++;
                    if (row + 1 >= n || grid[row + 1][col] == 0) perimeter++;
                    if (col - 1 < 0 || grid[row][col - 1] == 0) perimeter++;
                    if (col + 1 >= m || grid[row][col + 1] == 0) perimeter++;
                }
            }
        }
        return perimeter;
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(n × m)`
- **Space Complexity:** `O(1)`

---

## 🧪 Example

Input:
```
grid = [
  [0,1,0,0],
  [1,1,1,0],
  [0,1,0,0],
  [1,1,0,0]
]
```

Output:
```
16
```

---

## 🏁 Summary
- Simple grid traversal
- Constant space
- Clean and interview-friendly solution

Happy Coding! 🚀