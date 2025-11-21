# LeetCode 739 — Daily Temperatures

## Problem Summary

You are given an array `temperatures` where each element represents the temperature on a given day.  
For each day, you must determine how many days you need to wait until a warmer temperature appears.  
If no such future day exists, the answer for that day is `0`.

### Example
**Input:**  
`temperatures = [73,74,75,71,69,72,76,73]`

**Output:**  
`[1,1,4,2,1,1,0,0]`

---

## Brute Force Approach (TLE)

A straightforward solution is to check, for each day `i`, all future days `j > i` until a warmer temperature is found.

While correct, this approach has a worst-case time complexity of **O(n²)**, which results in a Time Limit Exceeded (TLE) for large inputs on LeetCode.

### Code (TLE)
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            while (j < n) {
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
                j++;
            }
        }
        return answer;
    }
};
```

### Why It Fails
- For each index, the algorithm may scan all remaining days.
- This results in up to `500 × 500` comparisons.
- Too slow → TLE on larger test cases.

---

## Optimized Approach — Monotonic Stack (O(n))

A more efficient method uses a **monotonic decreasing stack** to track indices whose warmer future day hasn’t been found yet.

### Key Idea
- Store indices of days in a stack.
- Maintain the stack in decreasing order of temperature.
- When a warmer temperature appears, it becomes the next warmer day for the top of the stack.

### Why This Works
- Each index is pushed and popped at most once → **O(n)** time.
- Avoids redundant checks performed in the brute-force method.

### Optimized Code
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        // Stack stores indices of days, with decreasing temperatures.
        stack<int> stack;

        for (int i = 0; i < n; i++) {
            // If current temperature is warmer than the temperature at stack top:
            // current day is the next warmer day for that index.
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int last = stack.top();
                stack.pop();
                answer[last] = i - last;
            }

            // Push current index into stack.
            stack.push(i);
        }

        return answer;
    }
};
```


---

## Time & Space Complexity

| Approach         | Time Complexity | Space Complexity | Status     |
|------------------|-----------------|------------------|------------|
| Brute Force      | O(n²)           | O(1)             | TLE        |
| Monotonic Stack  | O(n)            | O(n)             | Accepted   |

---

