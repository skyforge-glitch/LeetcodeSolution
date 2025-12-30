# Diagonal Sum of a Matrix (LeetCode 1572)

## 📌 Problem Statement
Given a **square matrix** `mat`, return the **sum of the matrix diagonals**.

- The **primary diagonal** goes from the **top-left** to the **bottom-right**.
- The **secondary diagonal** goes from the **top-right** to the **bottom-left**.
- If the matrix has an **odd size**, the center element lies on **both diagonals** and should be counted **only once**.

---

## 🧠 Approach (Optimized)

We traverse the matrix **row by row** and:
- Add the element from the **primary diagonal**
- Add the element from the **secondary diagonal**
- Avoid double-counting when both diagonals meet at the center

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        int i = 0, j = n - 1;

        for (int row = 0; row < n; row++) {
            if (i == j)
                sum += mat[row][i];
            else
                sum += mat[row][i] + mat[row][j];

            i++;
            j--;
        }

        return sum;
    }
};
```

---

## 🔍 Example

### Input
```
mat = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```

### Output
```
25
```

### Explanation
- Primary diagonal: `1 + 5 + 9 = 15`
- Secondary diagonal: `3 + 5 + 7 = 15`
- Center element `5` counted once  
👉 Total = `15 + 15 - 5 = 25`

---

## ⏱️ Complexity Analysis

| Type | Complexity |
|-----|------------|
| Time | `O(n)` |
| Space | `O(1)` |

---

## ⭐ Key Notes
- Works for **both even and odd** sized matrices
- No extra memory used
- Clean and interview-friendly solution

---

## 🏁 Conclusion
This is the **most optimal approach** to compute the diagonal sum of a square matrix efficiently.

Happy Coding 🚀
