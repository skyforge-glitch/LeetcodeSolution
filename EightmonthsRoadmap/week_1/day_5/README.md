# 📘 Sliding Window & Binary Search – LeetCode Solutions

This README covers **two problems**, focusing only on:
- Approach
- Code
- Time & Space Complexity

---

## 🔹 1. Longest Repeating Character Replacement (Sliding Window)

### 🧠 Approach
- Use a sliding window `[left … right]`
- Maintain frequency of characters in the window
- Track `maxFreq` = highest frequency of a single character
- If `(window size - maxFreq) > k`, shrink the window
- Keep updating the maximum valid window length

### 💻 Code
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> freq;
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
            maxFreq = max(maxFreq, freq[s[i]]);

            if ((i - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};
```

### ⏱️ Complexity
| Metric | Value |
|------|------|
| Time | O(n) |
| Space | O(1) |

---

## 🔹 2. Koko Eating Bananas (Binary Search)

### 🧠 Approach
- The answer lies between `1` and `max(piles)`
- Binary search on eating speed `k`
- For each `k`, calculate total hours required
- If hours > `h`, increase speed
- Else, try a smaller speed

### 💻 Code
```cpp
class Solution {
public:
    long long hourEating(vector<int>& piles, int mid) {
        long long hours = 0;
        for (long long x : piles) {
            hours += (x + mid - 1) / mid;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hourEating(piles, mid) > h)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
```

### ⏱️ Complexity
| Metric | Value |
|------|------|
| Time | O(n log m) |
| Space | O(1) |

---