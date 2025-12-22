# Stack Based Problems (LeetCode)

This repository contains solutions to three popular **stack-based problems** from LeetCode. Each solution uses an efficient approach and is implemented in **C++**.

---

## 1. Daily Temperatures

### Approach
- Use a **monotonic decreasing stack** that stores indices of days.
- Traverse the array from left to right.
- When the current temperature is higher than the temperature at the stack top index:
  - Pop the index from the stack
  - Calculate the difference in days
- Push the current index onto the stack.

### Code
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
```

### Complexity
| Type | Complexity |
|----|----|
| Time | O(n) |
| Space | O(n) |

---

## 2. Min Stack

### Approach
- Use **two stacks**:
  - One stack to store all values
  - One stack to track the minimum value at each state
- On push:
  - Push value to main stack
  - Push to min stack if it is smaller than or equal to current minimum
- On pop:
  - Remove from min stack if popped value is the current minimum

### Code
```cpp
class MinStack {
private:
    vector<int> arr;
    vector<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        arr.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (arr.empty()) return;
        if (arr.back() == minStack.back()) {
            minStack.pop_back();
        }
        arr.pop_back();
    }
    
    int top() {
        if (arr.empty()) return -1;
        return arr.back();
    }
    
    int getMin() {
        if (minStack.empty()) return -1;
        return minStack.back();
    }
};
```

### Complexity
| Type | Complexity |
|----|----|
| Time | O(1) per operation |
| Space | O(n) |

---

## 3. Valid Parentheses

### Approach
- Use a **stack** to store opening brackets.
- Traverse the string character by character:
  - Push opening brackets onto the stack
  - For closing brackets:
    - Check if stack is empty
    - Check if the top of the stack matches the closing bracket
- At the end, the stack should be empty for the string to be valid.

### Code
```cpp
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> st;

        for (char c : s) {
            if (mp.count(c)) {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (mp[st.top()] == c) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
```

### Complexity
| Type | Complexity |
|----|----|
| Time | O(n) |
| Space | O(n) |

---

## Summary
- All problems are solved using **stack-based techniques**
- Solutions are optimal and interview-ready
- Focus on:
  - Monotonic stack pattern
  - Auxiliary stack usage
  - Matching bracket logic

---