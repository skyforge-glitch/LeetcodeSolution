# LeetCode 1018 — Binary Prefix Divisible By 5

## 🔍 Problem Summary

You are given a binary array `nums`, where each element is either `0` or `1`.

For every prefix of this array, form the binary number represented by that prefix and check whether it is **divisible by 5**.

Return a boolean array `ans` where:

- `ans[i] = true` if the binary number formed by `nums[0..i]` is divisible by 5  
- otherwise, `ans[i] = false`.

### Example  
**Input:**  
`nums = [1,0,1]`

Prefixes:  
- `1` → 1 (not divisible)  
- `10` → 2 (not divisible)  
- `101` → 5 (divisible ✓)

**Output:**  
`[false, false, true]`

---

## 🧠 Key Insight

Binary numbers grow extremely large, so converting every prefix to an integer is not feasible.

### Trick: Use Modulo 5  
We only track the prefix **remainder modulo 5**, not the whole number.

Update rule when adding a bit `b`:

```
new_number = old_number * 2 + b
new_remainder = (old_remainder * 2 + b) % 5
```

This keeps values between 0–4, always manageable.

---

## ✅ Efficient Solution (O(n))

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;

        int mod = 0; // remainder modulo 5

        for (int num : nums){
            mod = (mod * 2 + num) % 5;
            ans.push_back(mod == 0);
        }

        return ans;
    }
};
```

---

## ⏱️ Time & Space Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | O(n) |
| **Space** | O(1) extra (ignoring output) |

---

## 📌 Key Takeaways

- Modulo arithmetic avoids big integer issues.
- Track remainder, not the full binary number.
- Efficient, simple, and optimal.