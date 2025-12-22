# LeetCode 567 — Permutation in String

## 📌 Problem Statement

Given two strings `s1` and `s2`, return `true` if `s2` contains a **permutation** of `s1`, otherwise return `false`.

A permutation means rearranging the characters of `s1`.  
For example:
- `s1 = "ab"` → permutations: `"ab"`, `"ba"`
- If `s2` contains `"ab"` or `"ba"` as a substring, the answer is `true`.

---

## 🧠 Core Idea

We use the **Sliding Window + Frequency Map** technique.

### Key Observations:
- A permutation of `s1` must:
  - Have the **same length** as `s1`
  - Contain the **same character frequencies**
- We slide a window of size `len(s1)` over `s2`
- At each step, we compare character frequencies

---

## 🛠️ Approach (Step-by-Step)

1. Count character frequencies of `s1`
2. Initialize a sliding window on `s2`
3. Expand the window by moving the right pointer
4. Shrink the window when its size exceeds `len(s1)`
5. Compare frequency maps at every step

If at any point the maps match → permutation found

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        unordered_map<char,int> freqS1;
        for (char c : s1) freqS1[c]++;

        unordered_map<char,int> freqS2;
        int left = 0;

        for (int i = 0; i < m; i++) {
            freqS2[s2[i]]++;

            if (i - left + 1 > n) {
                freqS2[s2[left]]--;
                if (freqS2[s2[left]] == 0)
                    freqS2.erase(s2[left]);
                left++;
            }

            if (freqS1 == freqS2) return true;
        }
        return false;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | `O(m)` |
| Space | `O(1)` (only 26 lowercase letters) |

---

## 🔍 Why This Works

- Sliding window ensures efficiency
- Hash maps guarantee accurate frequency matching
- Removing zero-frequency characters avoids false mismatches

---

## 🧪 Example Walkthrough

**Input**
```
s1 = "ab"
s2 = "eidbaooo"
```

**Window progression**
```
ei → id → db → ba ✅
```

Result: `true`

---

## 🚀 Final Thoughts

This problem is a **classic sliding window pattern** and frequently appears in interviews.

Master this approach and similar problems like:
- Anagrams in a string
- Longest substring with constraints
- Permutation checks

Happy Coding! 🎯
