# LeetCode 167 — Two Sum II (Input Array Is Sorted)

## 📝 Problem Summary
You are given:
- A **sorted** integer array `numbers`.
- A target integer `target`.

Your task is to return **1‑indexed** positions of two numbers such that:

```
numbers[i] + numbers[j] == target
```

You must use the **two-pointer technique** or another efficient method.  
The problem guarantees **exactly one solution** and **no element can be used twice**.

---

## 🚀 Example

### Input
```
numbers = [2,7,11,15], target = 9
```

### Output
```
[1, 2]
```

### Explanation
`2 + 7 = 9`, and their **1-based indices** are `1` and `2`.

---

## 💡 Key Insight
Because the array is **sorted**, we can use two pointers:

- `left` starts at the beginning
- `right` starts at the end

Shift pointers based on whether the current sum is too big or too small.

This gives **O(n)** time complexity and **O(1)** space.

---

## ✅ Two-Pointer Solution (C++)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // 1-based indexing
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }

        return {}; // Should never reach here (guaranteed one solution)
    }
};
```

---

## 🧠 Why Two Pointers Work

Because the array is sorted:

- If `sum > target`: decreasing the sum requires moving `right--`
- If `sum < target`: increasing the sum requires moving `left++`
- If equal → answer found

No need for hash maps → faster and simpler.

---

## 📈 Complexity
| Approach | Time | Space |
|---------|------|-------|
| Two pointers | **O(n)** | **O(1)** |

---

## 🔚 Final Notes
- The array is sorted → use two pointers, not brute force.
- Always return positions as **1-based**.
- There is guaranteed to be **exactly one valid pair**.

Happy coding! 🚀

---