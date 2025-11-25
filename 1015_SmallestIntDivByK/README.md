# ✅ LeetCode 1015 — Smallest Integer Divisible by K

## 🔍 Problem Summary
You are given an integer `k`.  
You must find the **smallest positive integer** that:

- is made **only of the digit `1`** (like `1`, `11`, `111`, …)
- and is **divisible by `k`**

Return the **number of digits** in that integer.

If no such number exists, return `-1`.

---

## 📌 Key Observation

A number made only of `1`s will **never** be divisible if:

- `k` is divisible by **2**
- `k` is divisible by **5**

Because such numbers always end in `1`, so they cannot be divisible by 2 or 5.

So:

```cpp
if (k % 2 == 0 || k % 5 == 0) return -1;
```

---

## 🧠 Intuition

Instead of building numbers like:

```
1
11
111
1111
```

which becomes huge and impossible to store,
we only track the **remainder** when divided by `k`.

### Why this works
A remainder uniquely represents the current state.

We repeatedly do:

```
rem = (rem * 10 + 1) % k
```

This simulates adding another `1` at the end **without overflow**.

Once `rem == 0`, we found the answer ✅

---

## ✅ Algorithm Steps

1. If `k` divisible by 2 or 5 → return `-1`
2. Initialize:
   - `rem = 1 % k`
   - `len = 1` (we used one digit: "1")
3. While remainder is not zero:
   - update `rem = (rem * 10 + 1) % k`
   - increment `len`
4. Return `len`

---

## 📌 Code Implementation (C++)

```cpp
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int rem = 1 % k;
        int len = 1;
        while(rem != 0){
            rem = ((rem * 10) + 1) % k;
            len++;
        }
        return len;
    }
};
```

---

## 🧪 Example

### Input
```
k = 3
```

### Output
```
3
```

### Explanation
The number `111` is divisible by `3`  
Length = **3**

---

## ⏱️ Time & Space Complexity

- **Time Complexity:** `O(k)`  
  (worst case iteration before remainder repeats)

- **Space Complexity:** `O(1)`  
  only storing a few integers

---

## ✅ Final Notes

- No need to construct the actual number
- Just simulate using remainders
- Works efficiently even for large `k`