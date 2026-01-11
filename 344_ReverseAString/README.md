# Reverse String (LeetCode)

## 📌 Problem Statement
Given a character array `s`, reverse the array **in-place**.
You must do this by modifying the input array directly, without using extra space.

---

## 🧠 Approach
We use the **two-pointer technique**:

- Initialize two pointers:
  - `left` at the start of the array
  - `right` at the end of the array
- Swap the characters at `left` and `right`
- Move `left` forward and `right` backward
- Continue until the pointers meet or cross

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
```

---

## ⏱ Time Complexity
- **O(n)** — where `n` is the number of characters

## 📦 Space Complexity
- **O(1)** — in-place reversal, no extra space used

---

## ✅ Key Points
- Efficient and simple solution
- Uses constant extra space
- Common interview question

---

✨ Happy Coding!