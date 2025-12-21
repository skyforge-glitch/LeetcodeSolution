# 🍌 LeetCode 875 — Koko Eating Bananas

## 📌 Problem Overview

Koko loves to eat bananas. There are `n` piles of bananas, where the `i-th` pile has `piles[i]` bananas.  
The guards have gone and will return in `h` hours.

Koko can decide her eating speed `k` (bananas/hour).  
Each hour, she chooses **one pile** and eats up to `k` bananas from that pile.  
If the pile has fewer than `k` bananas, she eats all of them and does nothing else for that hour.

---

## 🎯 Objective

Return the **minimum integer eating speed `k`** such that Koko can finish all the bananas within `h` hours.

---

## 🔍 Key Observations

- Koko **must eat all bananas** before `h` hours.
- She eats from **only one pile per hour**.
- Eating speed `k` is **constant throughout**.
- If `k` is too small → total hours needed increases.
- If `k` is large → total hours needed decreases.

👉 This creates a **monotonic relationship**, which strongly hints at **Binary Search on Answer**.

---

## 🧠 Core Intuition

Instead of simulating all possible strategies, we ask:

> ❓ *If Koko eats at speed `k`, can she finish within `h` hours?*

- If **YES**, try a **smaller `k`**
- If **NO**, try a **larger `k`**

This allows us to binary search on `k`.

---

## 📐 Mathematical Insight

For a pile of size `x` and eating speed `k`:

```
hours needed = ceil(x / k)
```

Which can be safely computed as:

```
(x + k - 1) / k
```

---

## 🛠️ Algorithm

1. **Search Space**
   - Minimum speed = `1`
   - Maximum speed = `max(piles)`

2. **Binary Search**
   - For each mid speed:
     - Compute total hours required
     - Compare with `h`

3. **Adjust Search**
   - If hours > h → speed too slow → move right
   - Else → speed valid → move left

4. **Return**
   - The smallest valid speed found

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    long long hourEating(vector<int>& piles, int mid) {
        long long hours = 0;
        for (long long x : piles) {
            if (x % mid == 0)
                hours += x / mid;
            else
                hours += x / mid + 1;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;

        for (int pile : piles)
            high = max(high, pile);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = hourEating(piles, mid);

            if (hours > h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | O(n log max(piles)) |
| Space | O(1) |

---

## ✅ Final Takeaway

This problem is a **classic Binary Search on Answer** example.  
Mastering this pattern helps solve many optimization problems efficiently.

Happy Coding 🚀
