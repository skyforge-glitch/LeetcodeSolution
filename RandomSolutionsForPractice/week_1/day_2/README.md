# Two Pointers Practice (LeetCode)

This repository contains solutions to three classic **Two Pointers** problems from LeetCode. Each solution is implemented in **C++** using an efficient optimal approach.

---

## 1. Two Sum II – Input Array Is Sorted

### Approach
- Since the array is already sorted, we use **two pointers**:
  - `low` starting from the beginning
  - `high` starting from the end
- Calculate the sum of elements at both pointers
- If the sum is:
  - Equal to target → return indices
  - Greater than target → move `high` left
  - Less than target → move `low` right

### Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;

        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) return {low + 1, high + 1};
            else if (sum > target) high--;
            else low++;
        }
        return {-1};
    }
};
```

### Complexity
| Type | Complexity |
|-----|-----------|
| Time | O(n) |
| Space | O(1) |

---

## 2. Container With Most Water

### Approach
- Use two pointers at both ends of the array
- Calculate the area using:
  - `min(height[low], height[high]) * (high - low)`
- Move the pointer pointing to the **smaller height**, since that limits the area
- Keep updating the maximum water stored

### Code
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int maxWater = 0;

        while (low < high) {
            maxWater = max(maxWater, min(height[low], height[high]) * (high - low));

            if (height[low] < height[high]) low++;
            else high--;
        }
        return maxWater;
    }
};
```

### Complexity
| Type | Complexity |
|-----|-----------|
| Time | O(n) |
| Space | O(1) |

---

## 3. 3Sum

### Approach
- Sort the array first
- Fix one element and use **two pointers** for the remaining part
- Skip duplicate values for:
  - The fixed index `i`
  - The `low` and `high` pointers
- This ensures **unique triplets** only

### Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int low = i + 1, high = n - 1;

            while (low < high) {
                int sum = nums[low] + nums[high];
                if (sum > target) high--;
                else if (sum < target) low++;
                else {
                    res.push_back({nums[i], nums[low], nums[high]});

                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                }
            }
        }
        return res;
    }
};
```

### Complexity
| Type | Complexity |
|-----|-----------|
| Time | O(n²) |
| Space | O(1) (excluding output) |

---

## Summary
- All problems use the **Two Pointers** technique
- Solutions are optimal and accepted on LeetCode
- Focus areas:
  - Pointer movement logic
  - Duplicate handling (3Sum)
  - Space optimization

---