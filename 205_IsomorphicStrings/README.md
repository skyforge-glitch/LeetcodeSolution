# LeetCode 205 – Isomorphic Strings

## 🧠 Problem Statement
Given two strings `s` and `t`, determine if they are **isomorphic**.

Two strings are isomorphic if:
- Each character in `s` maps to exactly one character in `t`
- The mapping is consistent throughout the string
- No two different characters in `s` map to the same character in `t`

---

## ✅ Approach: Two Hash Maps

We use **two unordered maps**:
- `s → t` mapping
- `t → s` reverse mapping (to prevent collisions)

For each index `i`:
1. If `s[i]` was seen before, ensure it maps to `t[i]`
2. If `t[i]` was seen before, ensure it maps back to `s[i]`
3. If either condition fails → return `false`

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // mp1: mapping from characters in s -> characters in t
        // mp2: reverse mapping from characters in t -> characters in s
        unordered_map<char, char> mp1, mp2;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];

            // Check forward mapping consistency
            if (mp1.count(a) && mp1[a] != b) return false;

            // Check reverse mapping consistency
            if (mp2.count(b) && mp2[b] != a) return false;

            // Store mappings
            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};
```

---

## 🧪 Example

**Input**
```
s = "egg"
t = "add"
```

**Mapping**
```
e → a
g → d
```

Output: `true`

---

## ⏱ Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 🎯 Notes
- Clean and interview-safe solution
- Can be optimized to `O(1)` space using arrays if character range is fixed

---

## 🔗 Problem Link
- https://leetcode.com/problems/isomorphic-strings/
