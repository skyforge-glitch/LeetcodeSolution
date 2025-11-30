# 📘 LeetCode 1590 — Make Sum Divisible by P

This README contains a clear explanation and a fully commented C++ solution for **LeetCode 1590**.

---

## 🧩 Problem Summary

You are given:
- an integer array `nums`
- an integer `p`

Goal: Remove the **smallest length contiguous subarray** so that the **sum of the remaining array** becomes divisible by `p`.

Formally, after removing `nums[l..r]`, we want:

```
(sum(nums) - sum(nums[l..r])) % p == 0
```

If no such subarray exists, return **-1**.

---

## 🎯 Key Idea

Let:

```
total = sum(nums)
target = total % p
```

If `target == 0`, the array is already divisible — return **0**.

We need a subarray whose sum has remainder `target`:

```
subarray_sum % p = target
```

Using prefix sums:

```
prefix[i] = (nums[0] + ... + nums[i]) % p
```

Subarray `(j+1 .. i)` satisfies the condition if:

```
(prefix[i] - prefix[j]) % p == target
```

Rearranged:

```
prefix[j] == (prefix[i] - target + p) % p
```

Thus, we store prefix modulo values in a hashmap and search efficiently.

---

## ⏱️ Time & Space Complexity

- **Time:** O(n)  
- **Space:** O(n)

---

## ✅ Fully Commented C++ Solution

```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        // Compute total sum of the array
        long long total = 0;
        for (int x : nums) total += x;

        // Remainder that must be removed
        int target = total % p;

        // Already divisible → no need to remove anything
        if (target == 0) return 0;

        // prefix_mod → index
        unordered_map<int, int> mp;
        mp[0] = -1;   // handle subarray starting from index 0

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            // current prefix modulo
            prefix = (prefix + nums[i]) % p;

            // we want prefix[j] such that:
            // (prefix[i] - prefix[j]) % p == target
            int need = (prefix - target + p) % p;

            // if such prefix existed before, update answer
            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            // store/update this prefix remainder’s index
            mp[prefix] = i;
        }

        // if no valid subarray found → return -1
        return ans == nums.size() ? -1 : ans;
    }
};
```

---

## 📝 Example

**Input:**  
```
nums = [3,1,4,2], p = 6
```

**Total Sum:**  
```
3 + 1 + 4 + 2 = 10
10 % 6 = 4
```

We need a subarray with sum % 6 = 4 → `[4]` works.

**Output:**  
```
1
```

---

## 📎 Notes

- Prefix mod technique is essential for O(n) performance.
- Hash map stores last occurrence to minimize subarray length.
- Works efficiently on all constraints.

---