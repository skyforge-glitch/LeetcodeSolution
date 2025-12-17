# LeetCode 3 — Longest Substring Without Repeating Characters

## 🧩 Problem Statement

Given a string `s`, find the length of the **longest substring** without repeating characters.

A **substring** is a contiguous sequence of characters within a string.

---

## ✅ Constraints

- `0 ≤ s.length ≤ 10^5`
- `s` consists of English letters, digits, symbols, and spaces

---

## 💡 Key Insight

The problem is not about distances between repeated characters —  
it is about maintaining a **valid substring** where **all characters are unique**.

To achieve this efficiently, we use the **Sliding Window technique** combined with a **Hash Map**.

---

## 🪟 Sliding Window + Hash Map Approach

### Idea

- Use two pointers:
  - `left` → start of the current window
  - `right` → end of the current window
- Maintain a map that stores the **last index** of each character.
- If a character repeats **inside the current window**, move `left` just after its previous occurrence.
- Keep updating the maximum window size.

---

## 🧠 Algorithm

1. Initialize:
   - `left = 0`
   - `ans = 0`
   - `unordered_map<char, int> lastIndex`
2. Iterate through the string using `right`
3. If the character was seen before and lies inside the window:
   - Move `left = lastIndex[c] + 1`
4. Update the character's latest index
5. Update the maximum length
6. Return the result

---

## 🧪 Example Walkthrough

### Input
```
s = "abba"
```

### Steps
```
a → window = "a"
b → window = "ab"
b → repeat → move left → window = "b"
a → window = "ba"
```

### Output
```
2
```

---

## 🧑‍💻 C++ Implementation

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (lastIndex.count(c) && lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | `O(n)` |
| Space | `O(min(n, charset))` |

Each character is processed once, and the window slides efficiently.

---

## ⚠️ Common Mistakes

- Only calculating distance between repeated characters
- Not maintaining a valid window
- Forgetting to update the `left` pointer
- Returning `n` when all characters repeat (incorrect)

---

## 🎯 Interview Takeaway

> *We maintain a sliding window of unique characters.  
> When a duplicate appears, we move the start of the window past its last occurrence.*

---

## 📌 Related Problems

- LeetCode 159 — Longest Substring with At Most Two Distinct Characters  
- LeetCode 340 — Longest Substring with At Most K Distinct Characters  

---

Happy Coding 🚀

---