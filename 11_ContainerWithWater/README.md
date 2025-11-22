# 🧊 LeetCode 11 — Container With Most Water

## 📘 Problem Summary
You are given an array `height`, where each element represents the height of a vertical line on the x-axis.  
You must choose **two lines** such that together with the x-axis, they form a container that holds the **maximum amount of water**.

💡 Water stored = `min(height[left], height[right]) * (right - left)`

---

## ⚡ Intuition
A brute-force solution checks all pairs, resulting in **O(n²)** time.  
To optimize, use the **two-pointer technique**:

- Start with the widest container (left = 0, right = n - 1)
- The **shorter line** determines the water height
- Move the pointer pointing to the **shorter** line inward

This works because:
- Width decreases step by step
- Only increasing the smaller height can potentially increase area

---

## ✅ Optimal Solution — Two Pointers (O(n))

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;   // two pointers
        int water = 0;                    // store maximum area
        
        while (i < j) {
            // Calculate current container area
            water = max(water, min(height[i], height[j]) * (j - i));

            // Move pointer with smaller height
            if (height[i] < height[j]) 
                i++;
            else 
                j--;
        }
        return water;
    }
};
```
---

## 🕒 Time & Space Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | **O(n)** |
| **Space** | **O(1)** |

---

## 🔍 Example Walkthrough

### Input:
height = [1,8,6,2,5,4,8,3,7]


### Steps:

- **Start** → `i = 0`, `j = 8`  
  Area = `min(1, 7) * 8 = 8`

- **Move `i` → 1**  
  Area = `min(8, 7) * 7 = 49`

- Continue adjusting pointers…

- **Maximum area found = 49**

---

## 🧠 Why Two Pointers Work

- Maximum width is at the edges  
- To improve area, the **minimum height** must increase  
- Therefore we move the pointer pointing to the **shorter line**  
- Each pointer shifts inward at most `n` times → **O(n)** total

---

## 🏁 Final Notes

This problem beautifully shows how:

- Mathematical reasoning  
- Smart pointer movement  
- Eliminating unnecessary checks  

can reduce a brute-force **O(n²)** approach to a clean **O(n)** optimal solution.

---