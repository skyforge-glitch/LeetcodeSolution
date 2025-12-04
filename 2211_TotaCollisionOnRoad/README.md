# 🚗 LeetCode 2211 — Count Collisions on a Road

This folder contains the C++ solution for **LeetCode 2211 — Count Collisions on a Road**, along with a clean explanation of the logic and approach.

---

## 🧩 Problem Summary

You are given a string `directions` where each character represents a car:

- `'L'` — car moving left  
- `'R'` — car moving right  
- `'S'` — car standing still  

Cars can collide when moving into each other or into a stationary car. After a collision, involved cars turn into `'S'`.

Your task is to compute how many collisions will occur in total.

---

## 🎯 Key Insight

Some cars **can never collide**:

### ✔ Leading `'L'` cars
They move left into empty space.

### ✔ Trailing `'R'` cars
They move right into empty space.

Remove them from consideration.

After removing these safe cars, every remaining `'L'` or `'R'` inside the range **must collide**, because:

- `'R'` will eventually hit an `'S'` or `'L'`
- `'L'` will eventually hit an `'S'` or `'R'`

So the number of collisions equals:

👉 **Count of all non-'S' cars in the remaining middle segment**

---

## ⏱️ Time & Space Complexity

- **Time:** O(n)  
- **Space:** O(1)

This is the optimal possible solution.

---

## ✅ C++ Solution (with comments)

```cpp
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // Skip all leading 'L' cars — they move left forever with no collisions.
        while (i < n && directions[i] == 'L')
            i++;

        // Skip all trailing 'R' cars — they move right forever with no collisions.
        while (j >= 0 && directions[j] == 'R')
            j--;

        int collisions = 0;

        // Count all cars that must collide in the middle segment.
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S')
                collisions++;
        }

        return collisions;
    }
};
```

---

## 📦 Folder Structure

- `solution.cpp` — implementation  
- `README.md` — explanation (this file)

---

### 🚀 Happy Coding!