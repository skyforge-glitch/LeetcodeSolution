# 📘 LeetCode 2273 — Remove Anagrams

This folder contains the C++ solution for **LeetCode 2273 — Remove Anagrams**, along with a clear explanation of the logic and approach.

---

## 🧩 Problem Summary

You are given a list of strings `words`.  
Your task is to remove each word that is an **anagram of the previous word**, keeping only the **first word** from each consecutive anagram group.

Example:

Input:
```
["abba", "baba", "bbaa", "cd", "cd"]
```

Output:
```
["abba", "cd"]
```

---

## 🎯 Approach Overview

Two words are anagrams if, when sorted, they form the same string.

To solve:

1. Keep a variable `prev` to store the **sorted form** of the previous accepted word.
2. For each word:
   - Create a sorted version of it.
   - If the sorted version differs from `prev`, keep the word.
   - Otherwise skip it.
3. Update `prev` whenever a word is kept.

This preserves original order and removes **only consecutive anagrams**.

---

## ⏱️ Time & Space Complexity

- **Time Complexity:** O(n · m log m)  
  Sorting each word of length *m* takes *m log m*.

- **Space Complexity:** O(m)  
  Needed to hold the sorted copy.

---

## ✅ C++ Solution (with comments)

```cpp
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;       // final filtered list
        string prev = "";         // sorted version of last accepted word

        for (auto &w : words) {
            string sortedW = w;                    // copy of current word
            sort(sortedW.begin(), sortedW.end());  // sort to detect anagram

            // Keep the word only if it's NOT a consecutive anagram
            if (sortedW != prev) {
                ans.push_back(w);  // keep original
                prev = sortedW;    // update anagram signature
            }
        }

        return ans;
    }
};
```

---

## 📦 Folder Contents

- `solution.cpp` — main solution  
- `README.md` — explanation (this file)

---

### 🚀 Happy Coding!  