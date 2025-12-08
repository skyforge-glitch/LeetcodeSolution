# LeetCode 1925 – Count Square Sum Triples

## 📘 Problem Summary
Given an integer `n`, count the number of **triples (a, b, c)** such that:

```
a^2 + b^2 = c^2
1 ≤ a, b, c ≤ n
```

These are standard **Pythagorean triples**.

---

## 🚀 Approach
We loop through all valid `a` and `b`, compute:

```
c = sqrt(a² + b²)
```

A valid triple satisfies:

- `c` is an integer  
- `c ≤ n`

We count both `(a, b, c)` and `(b, a, c)` → so add **2** for each match.

---

## ✅ Optimized C++ Code

```cpp
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        vector<int> squares(251);
        for (int i = 0; i < 251; i++) squares[i] = i * i;

        for (int a = 2; a < n - 1; a++) {
            for (int b = a + 1; b < n; b++) {

                double c = sqrt(squares[a] + squares[b]);

                if (c == int(c) && c <= n)
                    ans += 2;
            }
        }

        return ans;
    }
};
```

---

## 🧠 Complexity
- **Time:** `O(n²)`
- **Space:** `O(n)`

This is optimal for the constraints (`n ≤ 250`).

---

## 📎 Notes
- A precomputed squares array removes repeated multiplications.
- Integer casting validates perfect square condition.
- `ans += 2` counts both permutations `(a, b)` and `(b, a)`.

---