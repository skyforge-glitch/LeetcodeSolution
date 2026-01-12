# LeetCode 1249 – Minimum Remove to Make Valid Parentheses

This README shows **two accepted approaches** to solve LeetCode 1249:
1. **Two-Pass Greedy (No Stack)** – Best approach
2. **Stack-Based Approach** – Easy to understand

---

## 📌 Problem Statement
Given a string `s` containing lowercase letters and parentheses `'('` and `')'`,
remove the **minimum number of parentheses** so that the resulting string is **valid**.

A string is valid if:
- Every '(' has a matching ')'
- Parentheses are in the correct order

---

## ✅ Solution 1: Two-Pass Greedy (No Stack) ⭐ (Best)

### 🧠 Idea
- First pass (left → right): remove extra ')'
- Second pass (right → left): remove extra '('
- Greedy and efficient, no stack needed

### 💻 C++ Code

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        int open = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
                temp.push_back(c);
            } else if (c == ')') {
                if (open > 0) {
                    open--;
                    temp.push_back(c);
                }
            } else {
                temp.push_back(c);
            }
        }

        string ans = "";
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && open > 0) {
                open--;
            } else {
                ans.push_back(temp[i]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

### ⏱ Complexity
- **Time:** O(n)
- **Space:** O(n)

---

## ✅ Solution 2: Stack-Based Approach

### 🧠 Idea
- Use a stack to store indices of '('
- Mark invalid parentheses
- Build result excluding invalid indices

### 💻 C++ Code

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> remove(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    remove[i] = true;
                }
            }
        }

        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!remove[i]) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
```

### ⏱ Complexity
- **Time:** O(n)
- **Space:** O(n)

---

## 🏆 Final Comparison

| Approach | Time | Space | Verdict |
|--------|------|-------|--------|
| Two-Pass Greedy | O(n) | O(n) | ✅ Best |
| Stack-Based | O(n) | O(n) | Correct |

---

✨ Happy Coding!