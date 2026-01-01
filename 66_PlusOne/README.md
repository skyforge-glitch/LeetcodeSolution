# Plus One (LeetCode 66)

## 📌 Problem Statement
You are given a **large integer** represented as an array of digits, where each digit is in the range `0–9`.
The digits are ordered such that the **most significant digit comes first**.

Your task is to **increment the integer by one** and return the resulting array of digits.

### Constraints
- `1 ≤ digits.length ≤ 100`
- `0 ≤ digits[i] ≤ 9`
- The integer does not contain leading zeros.

---

## 🧠 Approach & Intuition

This problem mimics **manual addition**:

1. Start from the **last digit** (least significant digit).
2. If the digit is **less than 9**, increment it and return the result immediately.
3. If the digit is **9**, convert it to `0` and propagate the carry to the left.
4. If all digits are `9`, insert `1` at the beginning.

---

## ✅ Algorithm Steps

1. Initialize a pointer at the last index.
2. Traverse digits from right to left:
   - If digit ≠ 9 → increment and return.
   - If digit = 9 → set to 0 and continue.
3. If traversal ends, insert `1` at the beginning.
4. Return the modified array.

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1;

        while (end >= 0) {
            if (digits[end] != 9) {
                digits[end]++;
                return digits;
            } else {
                digits[end] = 0;
                end--;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

---

## 🧪 Example Walkthrough

### Input
```
digits = [9, 9, 9]
```

### Output
```
[1, 0, 0, 0]
```

### Explanation
- All digits are `9`, so each becomes `0`
- A new leading `1` is added

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` (in-place modification)

---

## 📎 Notes
- No integer conversion is required (avoids overflow).
- Handles all edge cases efficiently.

---

⭐ If you find this helpful, consider starring the repository!
