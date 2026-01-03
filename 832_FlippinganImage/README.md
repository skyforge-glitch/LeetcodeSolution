
# Flip and Invert Image (LeetCode 832)

## 🧠 Problem Overview

You are given a **binary matrix** `image` where each element is either `0` or `1`.

You need to perform **two operations on each row**:

1. **Flip the row horizontally**  
   - Reverse the row.
2. **Invert the image**  
   - Replace every `0` with `1` and every `1` with `0`.

Return the final transformed image.

---

## 🚀 Approach

We solve this problem **in-place** using a **two-pointer technique** for each row.

### Key Observations:
- Flipping a row is equivalent to swapping symmetric elements from both ends.
- Inversion can be done using logical NOT (`!`).
- If two symmetric elements are **equal**, then after flipping they will remain the same — so we invert them.
- If they are **different**, flipping already changes their positions and inversion cancels out, so no action is needed.

This allows us to perform **flip + invert in one pass**.

---

## 💡 Algorithm

For each row in the matrix:
1. Initialize two pointers:
   - `i` at the start
   - `j` at the end
2. While `i <= j`:
   - If `row[i] == row[j]`, invert both.
   - Move `i++` and `j--`.

---

## 🧩 C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size(); // Number of columns (image is square)

        // Iterate over each row
        for (auto& row : image) {
            int i = 0, j = n - 1; // Two pointers for flipping

            // Process until pointers cross
            while (i <= j) {
                // If both elements are same, flipping won't change them,
                // so we invert both values
                if (row[i] == row[j]) {
                    int newVal = !row[i]; // Invert 0->1 or 1->0
                    row[i] = row[j] = newVal;
                }
                // Move pointers inward
                i++;
                j--;
            }
        }
        return image;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`  
  - Each element is visited once.
- **Space Complexity:** `O(1)`  
  - In-place modification, no extra space used.

---

## ✅ Example

**Input:**
```
[[1,1,0],
 [1,0,1],
 [0,0,0]]
```

**Output:**
```
[[1,0,0],
 [0,1,0],
 [1,1,1]]
```

---

## 📌 Notes

- This solution is optimal and avoids extra memory.
- Combining flip and invert in one traversal improves performance.
- Works for both even and odd-length rows.

---

⭐ If you found this helpful, consider starring the repo!
