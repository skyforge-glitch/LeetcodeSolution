
# ✖️ LeetCode 43 — Multiply Strings

## 🧩 Problem Overview

You are given two **non-negative integers** represented as strings, `num1` and `num2`.

Your task is to **return their product**, also represented as a string.

### 🚫 Constraints
- You must **not** convert the entire string into an integer directly.
- You must **not** use built-in big integer libraries.
- The input strings may be very large (up to ~110 digits).

---

## 🔍 Example

**Input**
```
num1 = "123"
num2 = "456"
```

**Output**
```
"56088"
```

---

## 💡 Key Insight

This problem is a direct simulation of **grade-school multiplication**.

Instead of converting strings into numbers:
- Multiply digits one by one
- Store partial results in correct positions
- Handle carry manually
- Convert the final digit array into a string

---

## 🚀 Optimized Approach — Digit-by-Digit Multiplication

### 🧠 Core Idea

If:
- `num1` has length `n`
- `num2` has length `m`

Then:
- The product can have at most `n + m` digits
- We use a vector of size `n + m` to store the result

Each digit multiplication contributes to **two positions**:
- `i + j + 1` → current digit
- `i + j` → carry

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> result(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--) {
            int k1 = num1[i] - '0';

            for (int j = len2 - 1; j >= 0; j--) {
                int k2 = num2[j] - '0';

                int prod = k1 * k2 + result[i + j + 1];
                result[i + j + 1] = prod % 10;
                result[i + j] += prod / 10;
            }
        }

        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};
```

---

## 📊 Complexity Analysis

| **Metric**           | **Value** |
|----------------------|-----------|
| **Time Complexity**  | O(n × m)  |
| **Space Complexity** | O(n + m)  |

---

## 🔑 Key Takeaways

- This problem tests **string manipulation**, not arithmetic conversion
- Monitors how well you simulate real-world math operations
- Using a digit array avoids overflow and precision issues
- A foundational problem for understanding big-number arithmetic

---

## 🧠 Related Problems

- LeetCode 66 — Plus One
- LeetCode 415 — Add Strings
- LeetCode 556 — Next Greater Element III
- LeetCode 989 — Add to Array-Form of Integer

---

## 🎯 Conclusion

This problem reinforces:
- Manual carry handling
- Digit placement logic
- Safe handling of large numbers

---