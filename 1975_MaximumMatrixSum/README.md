# LeetCode 1975 — Maximum Matrix Sum

## 🧠 Problem Overview
You are given an `n x n` integer matrix.  
In one operation, you can **flip the sign** of any two adjacent elements (sharing an edge).

Your task is to **maximize the sum of the matrix** after performing any number of such operations.

---

## 🔍 Key Insight
- Using the allowed operations, we can effectively change the signs of elements.
- The **maximum sum** is achieved by making **all elements positive**, *except possibly one*.
- If the count of negative numbers is **odd**, one element must remain negative.
- To minimize loss, that element should have the **smallest absolute value**.

---

## ✅ Strategy
1. Traverse the matrix:
   - Add the absolute value of each element to the total sum.
   - Count how many elements are `<= 0`.
   - Track the minimum absolute value.
2. If the count of non-positive elements is **odd**, subtract `2 × minimum_absolute_value` from the sum.

---

## 🧩 C++ Solution (User's Implementation)

```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minm = INT_MAX, count = 0;
        long long sum = 0;

        for (int row = 0; row < n; row++){
            for (int col = 0; col < n; col++){
                if (matrix[row][col] <= 0) count++;

                minm = min(minm, abs(matrix[row][col]));
                sum += abs(matrix[row][col]);
            }
        }

        if (count % 2 != 0)
            return sum - (minm * 2);
        else
            return sum;
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(n²)` — every element is visited once.
- **Space Complexity:** `O(1)` — only constant extra space is used.

---

## 📝 Notes
- This solution is **optimal** in terms of time and space.
- The logic is based on **parity of negative numbers**, not their positions.

---

## 🔗 Reference
- LeetCode Problem: *Maximum Matrix Sum* (ID: 1975)

---

⭐ If you found this helpful, feel free to star the repo!
