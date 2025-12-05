# LeetCode 3432 — Count Partitions With Even Sum Difference

## 🧩 Problem Summary

You’re given an integer array `nums` of length `n`.  
A **partition** is defined by choosing an index `i` (0 ≤ i < n–1), splitting the array into:

- Left: `nums[0..i]`  
- Right: `nums[i+1..n-1]`

You must count how many such partitions satisfy:

**abs(sum(left) − sum(right)) is even**

---

## 🎯 Key Insight

Let:

- `total = sum(nums)`
- `left = sum(nums[0..i])`
- `right = total − left`

Difference:

```
left − right = 2*left − total
```

`2*left` is always **even**, so parity depends entirely on `total`.

### ✔ If `total` is odd → difference is always odd → **0 valid partitions**  
### ✔ If `total` is even → difference is always even → **all (n−1) partitions are valid**

---

## ⏱️ Complexity

- **Time:** O(n)  
- **Space:** O(1)

---

## ✅ C++ Code

```cpp
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0;
        for (int x : nums) total += x;
        if (total % 2 == 1) return 0;
        return nums.size() - 1;
    }
};
```

---

## 📦 Notes

- No prefix sums needed  
- No loops over partition positions  
- Pure parity logic  

---

### 🚀 Happy Coding!
