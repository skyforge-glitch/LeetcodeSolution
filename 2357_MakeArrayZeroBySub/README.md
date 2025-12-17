# LeetCode 2357 – Make Array Zero by Subtracting Equal Amounts

## 🧩 Problem Summary
You are given an integer array `nums`. In one operation, you can select the **smallest non-zero element** and subtract it from all non-zero elements.

Return the **minimum number of operations** required to make all elements equal to zero.

---

## 💡 Key Observation
Each operation eliminates **one distinct non-zero value** from the array.

👉 Therefore:
> **Minimum operations = Number of distinct non-zero elements**

No simulation is required.

---

## 🏆 Solutions (Worst → Best)

### ❌ 1. Using `vector<bool>` (Worst – Constraint Dependent)

This approach tracks whether a number has already appeared using a boolean array.

⚠️ **Drawback**: Assumes a fixed upper bound on values (e.g. `nums[i] ≤ 101`).  
Not safe if constraints change.
But can be used here, since constraints are provided.

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> operation(101, false); // nums[i] <= 101
        int op = 0;

        for (int x : nums) {
            if (x != 0 && !operation[x]) {
                operation[x] = true;
                op++;
            }
        }
        return op;
    }
};
```

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)` (constant but constraint-dependent)

---

### ⚠️ 2. Using `unordered_map` (Better)

Uses a hash map to count frequencies of non-zero elements.

✔ Correct but **frequency is unnecessary**, making it slightly overkill.

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            if (x != 0) {
                freq[x]++;
            }
        }
        return freq.size();
    }
};
```

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

---

### ✅ 3. Using `unordered_set` (Best – Recommended)

Stores only distinct non-zero values.  
✔ Clean, expressive, and constraint-independent.

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            if (x != 0) {
                st.insert(x);
            }
        }
        return st.size();
    }
};
```

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

---

## ⏱️ Time & Space Complexity Comparison (Worst → Best)

| Solution Approach | Best Case Time | Average Case Time | Worst Case Time | Space Complexity |
|------------------|----------------|-------------------|-----------------|------------------|
| `vector<bool>` (constraint-based) | O(n) | O(n) | O(n) | O(1) ⚠️ (value-range dependent) |
| `unordered_map` | O(n) | O(n) | O(n²) ⚠️ (hash collisions) | O(n) |
| `unordered_set` | O(n) | O(n) | O(n²) ⚠️ (hash collisions) | O(n) |

### 🧠 Notes
- **Best case:** All elements are `0` or identical — still requires one full traversal.
- **Average case:** Hash-based containers (`unordered_map`, `unordered_set`) provide `O(1)` average insertion.
- **Worst case:** Severe hash collisions can degrade hash operations to `O(n)`, leading to `O(n²)` total time.
- **Space caution:** `vector<bool>` uses constant space but relies on fixed constraints (unsafe if value range changes).

### 🏆 Recommendation
Use **`unordered_set`** for interviews and production:
- Clean logic
- Constraint-independent
- Best balance of clarity and performance

---

## ✅ Conclusion
All three approaches are correct.

**Recommended approach for interviews and production:**  
👉 **`unordered_set`**, because it is:
- Simple
- Robust
- Constraint-independent
- Clearly expresses the core idea

---

📌 *Key takeaway*: Don’t simulate the operations — **count distinct non-zero elements**.

---