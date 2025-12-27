# LeetCode 8 – String to Integer (atoi)

## 🧩 Problem Statement
Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer following rules similar to the C/C++ `atoi` function.

The algorithm should:
1. Ignore leading whitespace.
2. Handle an optional '+' or '-' sign.
3. Convert consecutive numeric digits into an integer.
4. Stop parsing at the first non-digit character.
5. Clamp the result to the 32-bit signed integer range if overflow occurs.

---

## 🚀 Approach

We scan the string from left to right using an index pointer.

Steps:
1. Skip all leading spaces.
2. Check for one optional sign.
3. Parse digits and build the number.
4. Perform overflow check before adding digits.
5. Apply sign and return result.

---

## 🧠 Overflow Handling

Overflow is prevented using this condition:

result > INT_MAX / 10  
OR  
result == INT_MAX / 10 AND digit > INT_MAX % 10

If overflow occurs:
- Return INT_MAX for positive numbers
- Return INT_MIN for negative numbers

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, result = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 ||
               (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
```

---

## ⏱ Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## 🧪 Example

Input:
```
"   -42"
```

Output:
```
-42
```

---

## ✨ Notes
- Only one optional sign is allowed.
- Parsing stops immediately on encountering a non-digit.
- Designed to match LeetCode's expected behavior precisely.

---

Happy Coding 🚀