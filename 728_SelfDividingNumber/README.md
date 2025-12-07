# LeetCode 728 – Self Dividing Numbers

## 🔍 Problem Summary
A **self-dividing number** is a number that:
- does **not** contain the digit `0`
- is divisible by **each of its digits**

Example:  
`128` → digits are 1, 2, 8  
Since `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`,  
it is a **self-dividing number**.

Given a range `[left, right]`, return all self-dividing numbers between them.

---

## 🧠 Approach
For each number in the range:
1. Extract digits using modulo and division.
2. If any digit is `0`, reject the number.
3. If the number is not divisible by any digit, reject it.
4. Otherwise, add it to the result.

This runs efficiently because each number has only a few digits.

---

## ⭐ Time Complexity
**O(n × digits)** — very fast in practice.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            int temp = i;
            bool ok = true;

            while (temp > 0) {
                int d = temp % 10;
                if (d == 0 || i % d != 0) {
                    ok = false;
                    break;
                }
                temp /= 10;
            }

            if (ok) ans.push_back(i);
        }

        return ans;
    }
};
```

---

## 📌 Example
Input:
```
left = 1, right = 22
```
Output:
```
[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
```

---

## 📎 Notes
- Zero digits automatically disqualify a number.
- Works for any positive integer range.

---