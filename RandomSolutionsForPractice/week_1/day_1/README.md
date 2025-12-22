# 📘 Array Problems – Solutions & Analysis

This document covers **three classic array problems**, including their **approach, code, time complexity, and space complexity**.

---

## 1️⃣ Concatenation of Array

### 🔹 Approach
- The size of the resulting array is twice the size of the input array.
- Use modulo indexing to repeat elements from the original array.
- Fill the new array sequentially.

### 🔹 Code
```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int m = 2 * nums.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int j = i % (m / 2);
            ans[i] = nums[j];
        }
        return ans;
    }
};
```

### ⏱️ Complexity Analysis

| Type | Complexity |
|----|----|
| Time | O(n) |
| Space | O(n) |

---

## 2️⃣ Running Sum of 1D Array

### 🔹 Approach
- Maintain a cumulative sum variable.
- Iterate through the array, adding each element to the sum.
- Replace the current element with the running sum.

### 🔹 Code
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};
```

### ⏱️ Complexity Analysis

| Type | Complexity |
|----|----|
| Time | O(n) |
| Space | O(1) |

---

## 3️⃣ Maximum Subarray (Kadane’s Algorithm)

### 🔹 Approach
- Use Kadane’s Algorithm.
- Maintain a current sum that represents the maximum subarray ending at the current index.
- Update the global maximum whenever a higher sum is found.

### 🔹 Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
```

### ⏱️ Complexity Analysis

| Type | Complexity |
|----|----|
| Time | O(n) |
| Space | O(1) |

---

✅ These solutions demonstrate **efficient array traversal**, **prefix computation**, and **optimal subarray selection**.

---