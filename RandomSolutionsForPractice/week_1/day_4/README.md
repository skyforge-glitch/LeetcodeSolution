# Sliding Window Problems – Combined README

This README documents **three sliding window based solutions**, written in C++, focusing on clarity and efficiency.

---

## 1. Maximum Average Subarray I

### Approach
- Use a **fixed-size sliding window** of length `k`.
- Maintain the current window sum.
- Slide the window by removing the left element and adding the next element.
- Track the maximum window sum and divide by `k` at the end.

### Code
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                maxSum = max(maxSum, currSum);
                currSum -= nums[left++];
            }
            currSum += nums[i];
        }
        maxSum = max(maxSum, currSum);
        return maxSum / double(k);
    }
};
```

### Complexity
| Metric | Value |
|------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

---

## 2. Minimum Size Subarray Sum

### Approach
- Use a **variable-size sliding window**.
- Expand the window until the sum is at least `target`.
- Shrink the window from the left to find the minimum length.
- Keep updating the minimum valid window length.

### Code
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0;
        int minLen = n + 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= target) {
                minLen = min(minLen, i - left + 1);
                sum -= nums[left++];
            }
        }
        return minLen == n + 1 ? 0 : minLen;
    }
};
```

### Complexity
| Metric | Value |
|------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

---

## 3. Longest Substring Without Repeating Characters

### Approach
- Use a **sliding window with a hash map**.
- Store the last index of each character.
- If a character repeats within the window, move the left pointer.
- Track the maximum window length.

### Code
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0, left = 0;

        for (int i = 0; i < n; i++) {
            if (mp.count(s[i]) && mp[s[i]] >= left) {
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
```

### Complexity
| Metric | Value |
|------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(k) (distinct characters) |

---

## Summary
These problems demonstrate how **sliding window techniques** can efficiently reduce brute-force solutions from quadratic to linear time.

Author: Akash Singh
