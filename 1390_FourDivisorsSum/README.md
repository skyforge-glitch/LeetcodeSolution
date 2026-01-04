# LeetCode 1390 – Four Divisors

## 🧩 Problem Overview

Given an array of integers `nums`, return the **sum of divisors** of each integer that has **exactly four divisors**.  
If a number does **not** have exactly four divisors, it contributes **0** to the final sum.

---

## 🔍 Key Insight

A number can have **exactly 4 divisors** only in two cases:

1. `p³` where `p` is a prime  
   - Divisors: `1, p, p², p³`
2. `p × q` where `p` and `q` are **distinct primes**  
   - Divisors: `1, p, q, p*q`

Using this insight, we can efficiently determine valid numbers.

---

## 🚀 Optimized Approach (√n)

Instead of checking all numbers from `1` to `num`, we:

- Iterate divisors only up to `√num`
- Count divisors in **pairs**
- Exit early if divisor count exceeds `4`
- Use **memoization** to avoid recomputation

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int divisors(int num) {
        int count = 0, sum = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                int d1 = i;
                int d2 = num / i;

                if (d1 == d2) {
                    count++;
                    sum += d1;
                } else {
                    count += 2;
                    sum += d1 + d2;
                }

                if (count > 4)
                    return 0;
            }
        }

        return (count == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        unordered_map<int,int> memo;

        for (int num : nums) {
            if (!memo.count(num))
                memo[num] = divisors(num);
            total += memo[num];
        }

        return total;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | `O(n √m)` |
| Space | `O(n)` |

- `n` → size of input array  
- `m` → maximum number in array  

---

## 🧪 Example

**Input**
```
nums = [21, 4, 7]
```

**Explanation**
- `21` → divisors `{1, 3, 7, 21}` → sum = `32`
- `4` → divisors `{1, 2, 4}` → ignored
- `7` → divisors `{1, 7}` → ignored

**Output**
```
32
```

---

## 🏁 Conclusion

This optimized solution efficiently solves the problem using:
- Mathematical pruning
- √n divisor traversal
- Memoization

Perfect for **interviews**, **competitive programming**, and **clean GitHub submissions** 🚀
