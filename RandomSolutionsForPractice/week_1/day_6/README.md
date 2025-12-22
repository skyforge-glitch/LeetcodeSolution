# Sliding Window & Binary Search — Practice Notes

This README contains **simple explanations** for two classic LeetCode problems solved using:
- Sliding Window + Hashing
- Binary Search

---

## 1️⃣ Permutation in String (LeetCode 567)

### 🔹 Approach
- Count character frequencies of `s1`
- Use a sliding window of size `len(s1)` on `s2`
- Maintain a frequency map for the current window
- Shrink window when size exceeds `s1`
- If both frequency maps match → permutation found

### 🔹 Code
```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        unordered_map<char,int> freqS1, freqS2;
        for(char c : s1) freqS1[c]++;

        int left = 0;
        for(int i = 0; i < m; i++){
            freqS2[s2[i]]++;

            if(i - left + 1 > n){
                freqS2[s2[left]]--;
                if(freqS2[s2[left]] == 0)
                    freqS2.erase(s2[left]);
                left++;
            }

            if(freqS1 == freqS2) return true;
        }
        return false;
    }
};
```

### ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | `O(m)` |
| Space | `O(1)` |

---

## 2️⃣ Find Minimum in Rotated Sorted Array (LeetCode 153)

### 🔹 Approach
- Use Binary Search
- Compare `nums[mid]` with `nums[high]`
- If mid > high → minimum lies on right side
- Else → minimum lies on left (including mid)
- Loop until `low == high`

### 🔹 Code
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
```

### ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | `O(log n)` |
| Space | `O(1)` |

---

### ✅ Notes
- Both solutions are **optimal**
- Frequently asked in interviews
- Clean logic with minimal edge cases

Happy Coding 🚀
