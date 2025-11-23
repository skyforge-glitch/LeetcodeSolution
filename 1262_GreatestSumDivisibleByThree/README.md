# LeetCode 1262 — Greatest Sum Divisible by Three

## Problem Statement

You are given an integer array `nums`.  

Return the **maximum possible sum** of elements from `nums` that is **divisible by 3**.

---

## Example 1

**Input:** 

```text
nums = [3, 6, 5, 1, 8]
```

**Output:**

```text
18
```


**Explanation:**

- Total sum = 3 + 6 + 5 + 1 + 8 = 23
- 23 % 3 = 2 → not divisible by 3
- Remove the smallest number(s) to fix remainder:
    - Remove 5 (remainder 2) → 23 - 5 = 18
- 18 % 3 = 0 → divisible
- Maximum sum = 18


## Example 2

**Input:**

```text
nums = [4]
```

**Output:**

```text
0
```

**Explanation:**

- Only number is 4 → 4 % 3 = 1 → not divisible
- Cannot remove anything else → maximum divisible sum = 0


---

## Approach 1: Greedy + Sorting (Simple Concept)

### Idea

1. Calculate `total = sum(nums)`  
2. Group numbers by remainder modulo 3:

- `mod1` → numbers where x % 3 = 1  
- `mod2` → numbers where x % 3 = 2  

3. If `total % 3 == 0` → already divisible → return total  
4. Otherwise, remove the minimum necessary numbers to fix remainder:

| remainder | Option 1                  | Option 2                  |
|-----------|---------------------------|---------------------------|
| 1         | remove 1 smallest mod1    | remove 2 smallest mod2    |
| 2         | remove 1 smallest mod2    | remove 2 smallest mod1    |

5. Pick the option with smallest sum removed  
6. Subtract it from total → result

---

### Code: Greedy + Sorting

```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> mod1, mod2;

        for (int x : nums) {
            total += x;
            if (x % 3 == 1) mod1.push_back(x);
            else if (x % 3 == 2) mod2.push_back(x);
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (total % 3 == 0) return total;

        int rm1 = INT_MAX, rm2 = INT_MAX;

        if (total % 3 == 1) {
            if (!mod1.empty()) rm1 = mod1[0];
            if (mod2.size() >= 2) rm2 = mod2[0] + mod2[1];
        } else { // total % 3 == 2
            if (!mod2.empty()) rm1 = mod2[0];
            if (mod1.size() >= 2) rm2 = mod1[0] + mod1[1];
        }

        return total - min(rm1, rm2);
    }
};
```

## Time & Space Complexity

| Metric | Complexity |
|--------|------------|
| Time   | O(n log n) → due to sorting mod1 and mod2 |
| Space  | O(n) → storing mod1 and mod2 |

---

## Approach 2: Dynamic Programming (Optimal)

### Idea

- Maintain 3 sums corresponding to remainder modulo 3:

```python

dp[0] = max sum divisible by 3
dp[1] = max sum with remainder 1
dp[2] = max sum with remainder 2
```


- For each number `x`, try adding it to all current dp states and update the new sums.  
- At the end, `dp[0]` holds the maximum sum divisible by 3.

---

### Code: DP Approach

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int x : nums) {
            vector<int> temp(dp); // copy current dp
            for (int r = 0; r < 3; r++) {
                int newSum = dp[r] + x;
                int newR = newSum % 3;
                temp[newR] = max(temp[newR], newSum);
            }
            dp = temp;
        }

        return dp[0];
    }
};
```

## Time & Space Complexity

| Metric | Complexity |
|--------|------------|
| Time   | O(n) → each number updates 3 states |
| Space  | O(1) → only 3 elements in dp array |

---

## Why DP is Better

- No sorting needed  
- No conditional “remove smallest numbers”  
- Works for large arrays efficiently  
- Clean and optimal solution

---

## Key Takeaways

- Modulo 3 arithmetic is the core.  
- Two approaches:  
  - Greedy + Sorting → easy to understand  
  - DP → optimal and elegant  
- Use `INT_MAX` or a large number to safely handle impossible removal options.  
- Always track remainder buckets or DP states to fix divisibility.

---